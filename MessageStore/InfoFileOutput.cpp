#include "InfoFileOutput.h"
namespace king::test
{
    bool InfoFileOutput::ShowMessage(const Message &, bool) const 
    {
            return true;
    }
    bool InfoFileOutput::ShowInfo(const string &) const 
    {
            return true;
    }
    bool InfoFileOutput::ShowMenu(const vector<string> &) const 
    {
            return true;
    }
    bool InfoFileOutput::ClearScreen() const 
    {
            return true;
    }
}