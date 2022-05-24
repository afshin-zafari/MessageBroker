#include "UserMessages.h"

namespace king::test
{
/*-------------------------------------------------------------------------------*/
    bool UsersMessages::SendMessage(const Message &message)  
    {
        user_messages.insert(pair<string,Message>(message.to,message));
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool UsersMessages::GetMessagesOfUser(const string &user,vector<Message> &messages) const 
    {
        auto list = user_messages.equal_range(user);
        messages.clear();
        for (auto it = list.first; it != list.second; it ++)
            messages.push_back(it->second);
        return true;
    }
/*-------------------------------------------------------------------------------*/
}
