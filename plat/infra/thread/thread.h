#ifndef __THREAD_H__
#define __THREAD_H__

#include "thread_log.h"
#include "thread_return.h"
#include "thread_info.h"

namespace thread {

ThreadRet RegisterThread()
{
    ThreadInfo* thread_info = ThreadInfo::getInstance();
    return ThreadRet::SUCCESS;
}

void SetThreadName(const char* name)
{
    ThreadInfo* thread_info = ThreadInfo::getInstance();
    thread_info->SetThreadName(name);
}

std::string& GetThreadName()
{
    ThreadInfo* thread_info = ThreadInfo::getInstance();
    return thread_info->GetThreadName();
}

}

#endif
