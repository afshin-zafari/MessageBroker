#include "InfoOutput.h"
namespace king::test
{
    bool InfoOutput::ShowMenu(const vector<string> &menu) const 
    {
        ClearScreen();
        cout << endl;
        for(const auto m: menu)
        {
            cout << m << endl;
        }
        return true;

    }
    bool InfoOutput::ShowInfo(const string &info) const 
    {
        cout << info << endl;
        return true; 

    }
    bool InfoOutput::ShowMessage(const Message &message, bool show_recipient) const 
    {
        cout << "From: " << message.from << endl; 
        if (show_recipient)
            cout << "To: " << message.from << endl; 
        cout << "Content: " << message.from << endl; 
        return true;
    }
    bool InfoOutput::ClearScreen() const 
    {
        string screen('\n',80);
        cout << screen;
        return true;
    }


}