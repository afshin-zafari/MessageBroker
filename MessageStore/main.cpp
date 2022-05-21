
#include "MessageStore.h"
#include "Application.h"
#include <cassert>
using namespace king::test;
void unit_test_example()
{
	Users users;
	InfoInput in;
	InfoOutput out;
	UsersMessages um;
	users.Add("A1");
	users.Add("B1");
	Message m1,m2;
	m1.from = m2.from = "A1";
	m1.to = m2.to = "B1";

	string  s1("Hello"), s2("Hey");
	m1.msg = s1;
	m2.msg = s2;
	um.SendMessage(m1);
	um.SendMessage(m2);
	vector<Message> messages;
	um.GetMessagesOfUser("B1", messages);
	assert (messages[0].msg == s1);
	assert (messages[1].msg == s2);
}
int main( int  , const char *[] )
{
	Users users;
	InfoInput in;
	InfoOutput out;
	UsersMessages um;

	unit_test_example();
	Application app(in,out,users,um);
	app.Run();
	return 0;
}
int old_main(int, const char* [])
{
	
	MessageStore store;;
	
	while (store.ProcessInput() == false){
	
	}
	
	store.terminate();
	
	return 0;
}
