#include "Users.h"
#include "InfoInput.h"
#include "InfoOutput.h"
#include "UserMessages.h"

namespace king::test
{
    class Application: public ApplicationInterface
    {
        public:

            Application (InfoInputPtr     &Input, 
                         InfoOutputPtr    &Output,
                         UsersPtr         &Users,
                         UsersMessagesPtr &UsersMessages);
            ~Application();
            void Run() override;

        private:
        
        UsersPtr         users;
        InfoInputPtr     input;
        InfoOutputPtr    output;
        UsersMessagesPtr user_messages;

        bool ProcessCommand    (int command);
        bool DoAddUser         ();
        bool DoShowUserMessages();
        bool DoSendMessage     ();
        bool GetValidUserName  (const char *prompt,string & user);
    };
}