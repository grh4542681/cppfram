#ifndef __PROCESS_MAIN_H__
#define __PROCESS_MAIN_H__

#include <utility>

#include "file.h"
#include "message_agent.h"

#include "process_log.h"
#include "process_return.h"
#include "process_info.h"
#include "group/process_group_keeper.h"

namespace process {

template < typename F >
class ProcessMain {
public:
    ProcessMain(std::string filename, F main) {
        config_filename_ = filename;
        main_ = main;
    }
    ~ProcessMain() { }

    template <typename ... Args>
    ProcessRet Run(int argc, char** argv, Args&& ... args) {
        // process info init
        ProcessInfo* process_info = ProcessInfo::getInstance();
        process_info->SetCmdLine(argc, argv, environ);
        if (process_info->GetProcessConfig().LoadFile(config_filename_) != config::ConfigRet::SUCCESS) {
            PROCESS_FATAL("Load process config file [%s] error", config_filename_.c_str());
            return ProcessRet::PROCESS_ECONFIG;
        }
        message::MessageAgent::getInstance()->Run();

        // exec main func
        auto config_pool = process_info->GetProcessConfig().GetRoot()->Search<bool>("process/group/switch");
        if (config_pool && config_pool->GetData()) {
            int group_size = process_info->GetProcessConfig().GetRoot()->Search<int>("process/group/size")->GetData();
            group::ProcessGroupKeeper<F, Args&& ...> group_(process_info->GetRealName(),
                            group_size,
                            process_info->GetProcessConfig().GetConfigFileName(),
                            main_, std::forward<Args>(args)...);
            group_.Run();
        } else {
            main_(std::forward<Args>(args)...);
        }
        return ProcessRet::SUCCESS;
    }

private:
    F main_;
    std::string config_filename_;
};

}

#endif
