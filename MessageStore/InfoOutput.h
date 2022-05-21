#include "Interfaces.h"
#include <iostream>

namespace king::test
{
    class InfoOutput : public InfoOutputInterface
    {
        public:
        bool ShowMessage(const Message &, bool s= false) const override;
        bool ShowInfo(const string &) const override ;
        bool ShowMenu(const vector<string> &) const override;
        bool ClearScreen() const override;
    };
}