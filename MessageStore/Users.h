#pragma once

#include "Interfaces.h"
#include <memory>

namespace king::test
{
    class Users : public UsersInterface
    {
        public:

        bool Exists(const string& u) const override;
        bool Add   (const string& u)       override;

        protected :
        
        set<string> users_set;        
    };
    typedef unique_ptr<Users> UsersPtr;
}