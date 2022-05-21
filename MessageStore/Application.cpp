#include "Application.h"
namespace king::test
{
    Application::Application(InfoInput & in,
                             InfoOutput & out,
                             Users & u,
                             UsersMessages& um)
        :
        users(make_unique<Users>(u)), 
        input(make_unique<InfoInput>(in)), 
        output(make_unique<InfoOutput>(out)),
        user_messages(make_unique<UsersMessages>(um))
    {
    }
    void Application::Run()
    {
        vector<string> menu;
        menu.push_back( "Please select an option:" );
	    menu.push_back("1. Create User" );
	    menu.push_back("2. Send Message" );
	    menu.push_back("3. Receive All Messages For User" );
	    menu.push_back("4. Quit" );
        int command;
        while(true)
        {
            output->ShowMenu(menu);
            if (!input->InputCommand(command))
                continue;
            if ( command == 4) 
                break;

            switch(command)
            {
                case 1:
                    DoAddUser();
                    break;
                case 2:
                    DoSendMessage();
                    break;
                case 3:
                    DoShowUserMessages();
                    break;
            }
            input->WaitForKey();
        }
    }
    bool Application::DoAddUser()
    {
        string user;
        input->InputUserName("Enter user name:",user);
        if (users->Exists(user))
        {
            output->ShowInfo(string(("User '") + user + "'already exists"));
            return false;
        }
        users->Add(user);
        return true;
    }
    bool Application::DoShowUserMessages()
    {
        string user;
        if ( !GetValidUserName("Enter name of user to receive all messages for:", user))
        {   
            return false;
        }
        vector<Message> messages;
        user_messages->GetMessagesOfUser(user, messages);
        output->ShowInfo(string("===== BEGIN MESSAGES ====="));
        for(const auto m: messages)
            output->ShowMessage(m);
        output->ShowInfo(string("===== END OF MESSAGES ====="));
        return true;
    }
    bool Application::GetValidUserName(const char * prompt, string & user)
    {
        input->InputUserName(string(prompt), user);
        if (!users->Exists(user))
        {
            output->ShowInfo(string("The user with name '") + user +  "' does not exist.");
            return false;
        }
        return true;

    }
    bool Application::DoSendMessage()
    {
        Message msg;
        if(GetValidUserName("From user:",msg.from))
            if(GetValidUserName("To user: ",msg.to))
                if ( input->Input(string("Content: "), msg.msg))
                {
                    user_messages->SendMessage(msg);
                    return true;
                }
        return false;
    }
}