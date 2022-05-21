#include "Application.h"
namespace king::test
{
    Application::Application(const InfoInput& in,
                             const InfoOutput&out,
                             const Users &u)
        :users(u), input(in), output(out)
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
        int cmd;
        while(true)
        {
            output.ShowMenu(menu);
            if (!input.InputCommand(cmd))
                continue;



        }
    }
}