#pragma once
#include "Interfaces.h"
#include <iostream>

namespace king::test
{
    class InfoOutput : public InfoOutputInterface
    {
        public:
        virtual bool ShowMessage(const Message &, bool s= false) const ;
        virtual bool ShowInfo(const string &) const override ;
        virtual bool ShowMenu(const vector<string> &) const override;
        virtual bool ClearScreen() const override;
    };
    typedef unique_ptr<InfoOutput> InfoOutputPtr;
}