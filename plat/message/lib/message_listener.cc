#include "message_agent.h"
#include "message_listener.h"

namespace message {
MessageListener::MessageListener(std::string name, const sock::SockAddress& addr)
{
    agent_ = MessageAgent::getInstance();
    info_.name_ = name;
    info_.endpoint_num_ = 0;
    info_.address_ = addr;
    info_.state_ = State::Initialize;
    server_ = sock::SockServer(&const_cast<sock::SockAddress&>(addr));
    if (server_.Bind() == sock::SockRet::SUCCESS)
    {
        printf("------- %s %d\n",__FILE__,__LINE__);
        info_.state_ = State::Ready;
        state_ = State::Ready;
    } else {
        printf("------- %s %d\n",__FILE__,__LINE__);
        info_.state_ = State::Error;
        state_ = State::Error;
    }
}

MessageListener::~MessageListener()
{

}

MessageListener::State& MessageListener::GetState()
{
    return state_;
}

sock::SockServer& MessageListener::GetSockServer()
{
    return server_;
}

bool MessageListener::IsReady()
{
    return (state_ == State::Ready);
}

io::IoRet MessageListener::_common_listener_callback(io::SelectItemTemplate<MessageListener>* item)
{

}

}
