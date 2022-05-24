#include "InfoOutput.h"

namespace king::test
{
/*-------------------------------------------------------------------------------*/
    bool InfoOutput::ShowMenu(const vector<string> &menu) const 
    {
        ClearScreen();
        cout << endl;
        for(const auto m: menu)
        {
            cout << m << endl;
        }
        cout <<  endl << endl << endl ; 
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool InfoOutput::ShowInfo(const string &info) const 
    {
        cout << info << endl;
        return true; 
    }
/*-------------------------------------------------------------------------------*/
    bool InfoOutput::ShowMessage(const Message &message, bool show_recipient) const 
    {
        cout << "From: " << message.from << endl; 
        if (show_recipient)
            cout << "To: " << message.to << endl; 
        cout << "Content: " << message.msg << endl; 
        return true;
    }
/*-------------------------------------------------------------------------------*/
    bool InfoOutput::ClearScreen() const 
    {
        string screen(80,'\n');
        cout << screen;
        return true;
    }
/*-------------------------------------------------------------------------------*/
}