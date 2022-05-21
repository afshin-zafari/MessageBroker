#include "Users.h"
#include "InfoInput.h"
#include "InfoOutput.h"

namespace king::test
{
    class Application: public ApplicationInterface
    {
        public:
            Application (const InfoInput& in, 
                         const InfoOutput&ou,
                         const Users &u);
            void Run() override;
        private:
        Users users;
        InfoInput input;
        InfoOutput output;
        bool DoAddUser(const string & u);

    };
}