
#include "MessageStore.h"
#include "Application.h"
#include "InfoFileOutput.h"
#include <cassert>

using namespace king::test;
/*-------------------------------------------------------------------------------*/
void unit_test_example_1()
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
/*-------------------------------------------------------------------------------*/
void unit_test_example_2()
{
	UsersPtr users = make_unique<Users>();
	InfoInputPtr  in = make_unique<InfoInput>();
	unique_ptr<InfoOutput> file_out = make_unique<InfoFileOutput>();
	//         ^                                  ^
	//         |--- BaseClass                     |--- CustomizedClass inherited from BaseClass
	UsersMessagesPtr  um = make_unique<UsersMessages>();

	Application app(in,file_out,users,um);
	app.Run();
}
/*-------------------------------------------------------------------------------*/
void unit_test_examples()
{
	unit_test_example_1();
	unit_test_example_2();
}
/*-------------------------------------------------------------------------------*/
int main( int  , const char *[] )
{
	UsersPtr users = make_unique<Users>();
	InfoInputPtr  in = make_unique<InfoInput>();
	unique_ptr<InfoOutput> out = make_unique<InfoOutput>();
	UsersMessagesPtr  um = make_unique<UsersMessages>();

	unit_test_examples();
	Application app(in,out,users,um);
	app.Run();
	return 0;
}
/*-------------------------------------------------------------------------------*/
int old_main(int, const char* [])
{
	
	MessageStore store;;
	
	while (store.ProcessInput() == false){
	
	}
	
	store.terminate();
	
	return 0;
}
/*-------------------------------------------------------------------------------*/
