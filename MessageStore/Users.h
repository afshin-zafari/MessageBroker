#include "Interfaces.h"
namespace king::test
{
    typedef string User;
    class Users : public UsersInterface<User>
    {
        public:
        bool Exists(const User& u) const override ;
        bool Add(const User& u)  override ;
        protected :
        set<string> users_set;
        
    };
}