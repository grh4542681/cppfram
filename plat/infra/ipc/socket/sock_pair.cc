#include <sys/types.h>
#include <sys/socket.h>

#include "sock_pair.h"

namespace ipc::sock {

SockPair::SockPair()
{
    init_flag_ = false;
    auto_close_ = false;
}

SockPair::SockPair(SockPair& other)
{
    init_flag_ = other.init_flag_;
    auto_close_ = other.auto_close_;
    fds_[0].setFD(other.fds_[0].getFD(), false);
    fds_[1].setFD(other.fds_[1].getFD(), false);
}

SockPair::~SockPair()
{
    if (init_flag_ && auto_close_) {
//        Close();
    }
}

void SockPair::SetAutoClose(bool flag)
{
    auto_close_ = true;
}

IpcRet SockPair::Open()
{
    int fds[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fds)) {
        return IpcRet::FIFO_ESOCKPAIR;        
    }

    //fds_[0] = socklib::SockFD(fds[0]);
    //fds_[1] = socklib::SockFD(fds[1]);
    fds_[0].setFD(fds[0], false);
    fds_[1].setFD(fds[1], false);
    init_flag_ = true;

    return IpcRet::SUCCESS;
}

void SockPair::Close()
{
    if (init_flag_) {
        fds_[0].Close();
        fds_[1].Close();
        init_flag_ = false;
    }
}

socklib::SockFD& SockPair::operator[] (const unsigned int index)
{
    if (index > 1) {
        IPC_ERROR("Bad index[%u] in pari fds", index);
        return fds_[2];
    }
    return fds_[index];
}

SockPair& SockPair::operator= (SockPair& other)
{
    init_flag_ = other.init_flag_;
    auto_close_ = other.auto_close_;
    fds_[0].setFD(other.fds_[0].getFD(), false);
    fds_[1].setFD(other.fds_[1].getFD(), false);
    return *this;
}

}