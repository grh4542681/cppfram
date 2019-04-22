/*******************************************************
 * Copyright (C) For free.
 * All rights reserved.
 *******************************************************
 * @author   : Ronghua Gao
 * @date     : 2019-04-22 13:51
 * @file     : shm_posix.h
 * @brief    : Posix share memory,
 * @note     : Email - grh4542681@163.com
 * ******************************************************/
#ifndef __SHM_POSIX_H__
#define __SHM_POSIX_H__
#include "ipc_log.h"
#include "ipc_return.h"
#include "shm.h"

namespace ipc::shm {

/**
* @brief - Posix share memory.
*/
class ShmPosix : public Shm {
public:
    /**
    * @brief ShmPosix - Constructor.
    *
    * @param [path] - Share memory name.
    */
    ShmPosix(std::string path);

    /**
    * @brief ShmPosix - Constructor.
    */
    ShmPosix();

    /**
    * @brief ~ShmPosix - Destructor.
    */
    ~ShmPosix();

    /**
    * @brief Create - Create share memory.
    *
    * @param [mode] - Share memory access mode.
    * @param [size] - Share memory size.
    *
    * @returns  IpcRet.
    */
    IpcRet Create(mode_t mode, size_t size);

    /**
    * @brief Destroy - Destroy share memory.
    *
    * @returns  IpcRet.
    */
    IpcRet Destroy();

    /**
    * @brief Open - Open share memory.
    *
    * @param [mode] - Share memory read-write mode.
    *
    * @returns  IpcRet.
    */
    IpcRet Open(IpcMode mode);

    /**
    * @brief Close - Close share memory.
    *
    * @returns  IpcRet.
    */
    IpcRet Close();

    /**
    * @brief Sync - Sync cache to share memory.
    *
    * @returns  IpcRet.
    */
    IpcRet Sync();

private:
    int fd_;    ///< Share memory file descriptor.

    ShmPosix(const ShmPosix& other);

    static IpcRet _errno2ret(int ierrno)
    {   
        switch (ierrno) {
            case 0:
                return IpcRet::SUCCESS;
            default:
                return IpcRet::EUNKOWNERRNO;
        }   
    }   

    static int _ret2errno(IpcRet ret)
    {   
        switch (ret) {
            case IpcRet::SUCCESS:
            default:
                return (-1);
        }   
    }
    
};

}//namespace ipc end

#endif
