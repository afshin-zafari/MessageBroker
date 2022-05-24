#include "InfoInput.h"

namespace king::test
{
/*-------------------------------------------------------------------------------*/
    bool InfoInput::InputCommand(int &command) const 
    {
        Input("Enter 1-4",command);
        if (command > 4 || command < 0) 
            return false;
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool InfoInput::InputMessage(Message &message) const 
    {
        Input("From: "    , message.from); 
        Input("To: "      , message.to  ); 
        Input("Ccontent: ", message.msg ); 
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool InfoInput::InputUserName(const string& prompt , string &user) const 
    {
        Input(prompt,user);
        return true;
    }
/*-------------------------------------------------------------------------------*/
    template<typename T>
    bool InfoInput::Input(const string& prompt, T& input) const 
    {
        cout << prompt ;
        cin  >> input  ;
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool InfoInput::WaitForKey() const 
    {
        cout << "Type something and press Enter to continue! ...." << endl;
        string temp;
        cin >> temp;
        return true;
    }
/*-------------------------------------------------------------------------------*/
}