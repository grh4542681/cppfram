#include <stdio.h>
#include "mempool.h"
#include "mempool_center.h"

namespace pub {

thread_local MemPool* MemPool::pInstance = NULL;

MemPool::MemPool()
{

}

MemPool::~MemPool()
{

}

void* MemPool::_malloc(size_t size)
{
    return malloc(size);
}

void MemPool::_free(void* ptr)
{
    free(ptr);
}

MemPool* MemPool::getInstance()
{
    if (!pInstance) {
        pInstance = new MemPool();
    }
    return pInstance;
}

}// namespace pub end
