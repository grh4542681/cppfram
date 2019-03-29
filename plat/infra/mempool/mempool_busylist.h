#ifndef __MEMPOOL_BUSYLIST_H__
#define __MEMPOOL_BUSYLIST_H__

#include <pthread.h>
#include <map>
#include <time.h>

#include "mempool_log.h"
#include "mempool_return.h"
#include "mempool_itemori.h"
#include "file.h"

namespace mempool {

class MemPoolBusyList {
public:
    struct MemPoolBusyItem {
        void* ptr_;
        time_t alloc_time_;
        MemPoolItemOri ori_;
    };
public:
    MemPoolBusyList();
    ~MemPoolBusyList();

    MemPoolRet Insert(void* ptr, MemPoolItemOri ori);
    MemPoolRet Remove(void* ptr);
    MemPoolItemOri Origin(void* ptr);
    
    unsigned int Size();
    MemPoolRet Clear();

    void Report(file::File& fd);

private:
    std::map<void*, MemPoolBusyItem> busy_map_;

};

};

#endif
