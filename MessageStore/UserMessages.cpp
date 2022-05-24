#include "UserMessages.h"

namespace king::test
{
/*-------------------------------------------------------------------------------*/
    bool UsersMessages::SendMessage(const Message &m)  
    {
        user_messages.insert(pair<string,Message>(m.to,m));
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool UsersMessages::GetMessagesOfUser(const string &u,vector<Message> &messages) const 
    {
        auto list = user_messages.equal_range(u);
        messages.clear();
        for (auto it = list.first; it != list.second; it ++)
            messages.push_back(it->second);
        return true;
    }
/*-------------------------------------------------------------------------------*/
}
