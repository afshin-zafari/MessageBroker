#include "Application.h"
namespace king::test
{
/*-------------------------------------------------------------------------------*/
    Application::Application(InfoInputPtr     &Input,
                             InfoOutputPtr    &Output,
                             UsersPtr         &Users,
                             UsersMessagesPtr &UserMessages)
        :
        users        (move(Users)       ), 
        input        (move(Input)       ), 
        output       (move(Output)      ),
        user_messages(move(UserMessages))
    {
    }
/*-------------------------------------------------------------------------------*/
    void Application::Run()
    {
        int command;
        vector<string> menu;

        menu.push_back("Please select an option:" );
	    menu.push_back("1. Create User" );
	    menu.push_back("2. Send Message" );
	    menu.push_back("3. Receive All Messages For User" );
	    menu.push_back("4. Quit" );

        try 
        {        
            while(true)
            {
                output->ShowMenu(menu);
                if (!input->InputCommand(command))
                {
                    output->ShowInfo(string("Please enter numbers between 1 to 4 for the options."));
                    continue;
                }
                if(!ProcessCommand(command))
                    break;
            }
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << '\n';
        }
    }
/*-------------------------------------------------------------------------------*/
    bool Application::ProcessCommand(int command)
    {
            if (command == 4) 
                return false;

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
                default:
                    break;
            }

            input->WaitForKey();

            return true;
    }
/*-------------------------------------------------------------------------------*/
    bool Application::DoAddUser() 
    {
        string user;

        input->InputUserName("Enter user name:",user);
        if (!users->Add(user))
        {
            output->ShowInfo(string("User '") + user + "'already exists");
            return false;
        }        
        output->ShowInfo(string("User '") + user + "' successfully added.");
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool Application::DoShowUserMessages()
    {
        string user;

        if ( !GetValidUserName("Enter name of user to receive all messages for:", user))
        {   
            return false;
        }

        vector<Message> messages;
        user_messages->GetMessagesOfUser(user, messages);
        if ( messages.size() > 0 )
        {
            output->ShowInfo(string("===== BEGIN MESSAGES ====="));
            for(const auto m: messages)
                output->ShowMessage(m);
            output->ShowInfo(string("===== END OF MESSAGES ====="));
        }
        else
        {
            output->ShowInfo(string("No message is sent to user'" ) + user + "' .");
        }
        return true;
    }
/*-------------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------------*/
    bool Application::DoSendMessage()
    {
        Message message;
        if(GetValidUserName("From user:",message.from))
        {
            if(GetValidUserName("To user: ",message.to))
            {
                if (input->Input(string("Content: "), message.msg))
                {
                    user_messages->SendMessage(message);
                    return true;
                }
            }
        }
        return false;
    }
/*-------------------------------------------------------------------------------*/
    Application::~Application()
    {
        input        .release();
        output       .release();
        users        .release();
        user_messages.release();
    }
}