#ifndef __IPC_FD_H__
#define __IPC_FD_H__

#include "ipc_fd_type.h"

namespace ipc {

class IpcFD {
public:
    IpcFDType fd_type_;
    bool init_flag_;

    IpcFD() {
        fd_type_ = IpcFDType::NONE;
        init_flag_ = false;
    }
    IpcFD(const IpcFD& other) {
        fd_type_ = other.fd_type_;
        init_flag_ = other.init_flag_;
    }
    virtual ~IpcFD() { }

    virtual int Read(void* data, unsigned int datalen) { return 0; };
    virtual int Write(const void* data, unsigned int datalen) { return 0; };

    IpcFD& operator= (const IpcFD& other) {
        init_flag_ = other.init_flag_;
        fd_type_ = other.fd_type_;
        return *this;
    }
};

}

#endif