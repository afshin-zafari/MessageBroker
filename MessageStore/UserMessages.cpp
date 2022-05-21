#include "UserMessages.h"
namespace king::test
{
    bool UsersMessages::SendMessage(const Message &m)  
    {
        user_messages.insert ( pair<string,Message>(m.to,m));
        return true;
    }
    bool UsersMessages::GetMessagesOfUser(const string &u,vector<Message> &v) const 
    {
        auto list = user_messages.equal_range(u);
        v.clear();
        for (auto it = list.first; it != list.second; it ++)
            v.push_back(it->second);
        return true;
    }
}
