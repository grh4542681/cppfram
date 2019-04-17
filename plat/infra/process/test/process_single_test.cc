#include <stdio.h>

#include "process_info.h"
#include "single/process_single.h"
#include "signal/process_signal.h"
#include "signal/process_signal_ctrl.h"
#include "signal/process_signal_action.h"
#include "signal/process_signal_common_callback.h"
#include "file_c.h"
#include "thread.h"
#include "report_mode.h"

extern char ** environ;

void test_process()
{
    printf("child [%d]\n",getpid());
    process::ProcessInfo* p = process::ProcessInfo::getInstance();
    printf("child [%d] name [%s]\n", p->GetPid(), p->GetProcessName().c_str());
    sleep(20);
}

void dead(int *status)
{
    printf("child [%d] dead\n",getpid());
}

int main(int argc, char** argv)
{
    process::ProcessInfo* p = process::ProcessInfo::getInstance();
    p->SetCmdLine(argc, argv, environ);
    process::signal::ProcessSignalCtrl* ps = process::signal::ProcessSignalCtrl::getInstance();
    ps->Register(process::signal::ProcessSignal(SIGCHLD), std::move(process::signal::ProcessSignalAction().SetCallback(process::signal::SignalCommonCallback_SIGCHLD)));

/*
    std::string i = "/home/ezgaoro/workspace/cppfram/bin/test/time_c_test";
    process::single::ProcessSingle<std::string> p2(i);
    p2.Run(NULL);
*/

    auto process_type = test_process;
    process::single::ProcessSingle<decltype(process_type)> p1("process_test_single:child1", test_process);
    p1.SetSigChldCallback(dead);
    p1.Run();

    sleep(5);
    file::FileC fd(stdout);
    p->Report(fd,report::ReportMode::DETAIL);

    sleep(25);
    p->Report(fd,report::ReportMode::DETAIL);
    return 0;
}
