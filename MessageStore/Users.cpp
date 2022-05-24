#include "Users.h"

namespace king::test
{
/*-------------------------------------------------------------------------------*/
    bool Users::Exists(const string& user) const
    {
        return users_set.contains(user);
    }
/*-------------------------------------------------------------------------------*/
    bool Users::Add(const string& user)  
    {
        auto [_,new_member] = users_set.insert(user);
        return !new_member;
    }
/*-------------------------------------------------------------------------------*/
}