#include <stdio.h>
#include "mempool.h"
#include "mempool_center.h"

namespace mempool {

thread_local MemPool* MemPool::pInstance = NULL;

MemPool::MemPool()
{
}

MemPool::~MemPool()
{

}

void MemPool::ReportCenter(file::File& fd)
{

}

void MemPool::ReportThread(file::File& fd)
{
    threadcache_.Report(fd);
}

//private
void* MemPool::_malloc(size_t size)
{
    return threadcache_.Alloc(size);
}

void MemPool::_free(void* ptr)
{
    threadcache_.Free(ptr);
}

MemPool* MemPool::getInstance()
{
    if (!pInstance) {
        pInstance = new MemPool();
    }
    return pInstance;
}

}// namespace pub end
