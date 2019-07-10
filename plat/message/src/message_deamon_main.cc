#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

#include <string>
#include <iostream>

#include "process_info.h"
#include "message_deamon.h"

int main(int argc, char** argv)
{
    //command line arguments
    std::string process_config_file = "";
    bool group_worker = false;
    int file_describe = 0;

    //command line process.
    char short_options[] = ":gp:f:h";
    struct option long_options[] = {
        {"group_worker", 0, 0, 'g'},
        {"process_config", 1, 0, 'p'},
        {"file_describe", 1, 0, 'f'},
        {"help", 0, 0, 'h'},
        {0, 0, 0, 0}
    };

    int option_val;
    int option_index = 0;
    while (1) {
        option_index = 0;
        option_val = getopt_long(argc, argv, short_options, long_options, &option_index);
        if (option_val == -1) {
            break;
        }
        switch (option_val) {
            case 0:
                break;
            case 'g':
                group_worker = true;
                break;
            case 'p':
                process_config_file.assign(optarg);
                break;
            case 'f':
                file_describe = *(reinterpret_cast<int*>(optarg));
                break;
            case 'h':
                std::cout << "Useage:" << std::endl;
                exit(0);
            case ':':
                std::cout << "Option [" << argv[optind-1] << "] need arguments" << std::endl;
                std::cout << "Please use [-h or --help] to see usage." << std::endl;
                exit(0);
            case '?':
                std::cout << "Unknow option [" << argv[optind] << "]" << std::endl;
                std::cout << "Please use [-h or --help] to see usage." << std::endl;
                exit(0);
            default:
                break;
        }
    }

    if (optind < argc) {
        std::cout << "Unknow option ";
        while (optind < argc)
            std::cout << "[" << argv[optind++] << "] ";
        std::cout << std::endl;
        std::cout << "Please use [-h or --help] to see usage." << std::endl;
        exit(0);
    }

    //process resource initlization.
    process::ProcessInfo* process_info = process::ProcessInfo::getInstance();
    if (group_worker) {
        process_info->GetProcessRole() |= process::ProcessRole::PoolWorker;
    }

    std::cout<<process_config_file<<std::endl;

    message::MessageDeamon deamon;
    deamon.Run();
    return 0;
}