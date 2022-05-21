#pragma once
#include "Interfaces.h"
#include <memory>
namespace king::test
{
    class UsersMessages: public UsersMessagesInterface<Message>
    {
        public:
        bool SendMessage(const Message &m)  override;
        bool GetMessagesOfUser(const string &,vector<Message> &) const override;
        private:
        multimap<string,Message> user_messages;
    };
    //typedef UsersMessages *UsersMessagesPtr;
    typedef unique_ptr<UsersMessages> UsersMessagesPtr;
}