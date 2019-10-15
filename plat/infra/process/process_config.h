#ifndef __PROCESS_CONFIG_H__
#define __PROCESS_CONFIG_H__

#include "config_static.h"

namespace process {

class ProcessConfig : public config::ConfigStatic {
public:
    ProcessConfig() {

    }
    ~ProcessConfig(){

    }

    config::ConfigRet LoadJson(parser::ParserJson& parser);

    container::NodeTree::ElementAny* GetMessageConfig();

};

}

#endif
