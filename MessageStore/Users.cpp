#include "Users.h"
namespace king::test
{
    bool Users::Exists(const User& u) const
    {
        return users_set.contains(u);
    }
    bool Users::Add(const User& u)  
    {
        users_set.insert(u);
        return true;
    }

}