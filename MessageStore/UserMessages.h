#pragma once

#include "Interfaces.h"

namespace king::test
{
    class UsersMessages: public UsersMessagesInterface<Message>
    {
        public:
        bool SendMessage      (const Message &message)                     override;
        bool GetMessagesOfUser(const string &user,vector<Message> &) const override;
        private:
        multimap<string,Message> user_messages;
    };
    typedef unique_ptr<UsersMessages> UsersMessagesPtr;
}