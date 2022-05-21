#pragma once
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace king::test
{
    struct Message {
		std::string from;
		std::string to;
		std::string msg;
	};
    class UsersInterface
    {
        public:
        virtual bool Exists(const string & u) const = 0 ;
        virtual bool Add(const string & u)  = 0;
    };
    template <typename MessageType>
    class UsersMessagesInterface
    {
        public:
        virtual bool SendMessage(const MessageType &m)  = 0;
        virtual bool GetMessagesOfUser(const string &, vector<Message> &) const =0;
    };
     
    class InfoInputInterface
    {
        public:
        virtual bool InputUserName(const string &,string &) const = 0;
        virtual bool InputMessage(Message &) const = 0;
        virtual bool InputCommand(int &) const = 0;
        virtual bool WaitForKey() const = 0;
        template<typename T>
        bool Input(const string prompt, T&) const ;
    };
    class InfoOutputInterface
    {
        public:
        virtual bool ShowMessage(const Message &, bool) const = 0;
        virtual bool ShowInfo(const string &) const = 0;
        virtual bool ShowMenu(const vector<string> &) const = 0;
        virtual bool ClearScreen() const = 0;
    };
    class ApplicationInterface
    {
        public:
            virtual void Run() = 0 ;
        protected:

    };
}