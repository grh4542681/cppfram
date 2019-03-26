#ifndef __MEMPOOL_FREELIST_H__
#define __MEMPOOL_FREELIST_H__

#include "mempool_sizemap.h"
#include "mempool_memorylist.h"

namespace mempool {

class MemPoolFreeList {
public:
    MemPoolFreeList();
    ~MemPoolFreeList();

private:
    MemPoolMemoryList list_array_[MemPoolSizeMap::g_sobj_array_size];

};

} //namespace end

#endif