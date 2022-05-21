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
    template <typename UserType>
    class UsersInterface
    {
        public:
        virtual bool Exists(const UserType & u) const = 0 ;
        virtual bool Add(const UserType& u)  = 0;
    };
    template <typename UserType, typename MessageType>
    class UsersMessagesInterface
    {
        public:
        virtual bool Exists(const UserType& u) const = 0 ;
        virtual bool Add(const UserType& u, const MessageType &m)  = 0;
        protected :
        multimap<string,MessageType> user_messages;
    };
     
    class InfoInputInterface
    {
        public:
        virtual bool InputUserName(const string &,string &) const = 0;
        virtual bool InputMessage(Message &) const = 0;
        virtual bool InputCommand(int &) const = 0;
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