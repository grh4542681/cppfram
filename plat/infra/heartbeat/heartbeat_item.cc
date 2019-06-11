#include "heartbeat_item.h"

namespace heartbeat {

HeartbeatItem::HeartbeatItem(baseio::FD& fd, util::time::Time& over_time)
{
    fd_ = fd.Clone();
    if (!fd_) {
        state_ = HeartbeatState::INVALID;
        return;
    }
    mempool_ = mempool::MemPool::getInstance();
    over_time_ = over_time;
    dead_time_ = over_time;
    over_callback_ = NULL;
    dead_callback_ = NULL;
}

HeartbeatItem::~HeartbeatItem()
{
    if (fd_) {
        mempool_->Free<baseio::FD>(fd_);
    }
}

baseio::FD* HeartbeatItem::GetFD()
{
    return fd_;
}

HeartbeatState HeartbeatItem::GetState()
{
    return state_;
}

util::time::Time& HeartbeatItem::GetLastTime()
{
    return last_time_;
}

util::time::Time& HeartbeatItem::GetOverTime()
{
    return over_time_;
}

util::time::Time& HeartbeatItem::GetDeadTime()
{
    return dead_time_;
}

HeartbeatItem& HeartbeatItem::SetLastTime(util::time::Time& last_time)
{
    last_time_ = last_time;
    return *this;
}

HeartbeatItem& HeartbeatItem::SetOverTime(util::time::Time& over_time)
{
    over_time_ = over_time;
    return *this;
}

HeartbeatItem& HeartbeatItem::SetDeadTime(util::time::Time& dead_time)
{
    dead_time_ = dead_time;
    return *this;
}

}
