#include "Interfaces.h"
#include <iostream>
namespace king::test
{
    class InfoInput : public InfoInputInterface
    {
        public:
        InfoInput();
        bool InputUserName(const string &, string &) const override ;
        bool InputMessage(Message &) const override ;
        bool InputCommand(int &) const override ;
        template<typename T>
        bool Input(const string prompt, T&) const ;
    };
}