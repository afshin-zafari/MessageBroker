#include "Users.h"
namespace king::test
{
    bool Users::Exists(const string& u) const
    {
        return users_set.contains(u);
    }
    bool Users::Add(const string& u)  
    {
        auto [_,new_member] = users_set.insert(u);
        return !new_member;
    }

}