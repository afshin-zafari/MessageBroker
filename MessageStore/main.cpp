
#include "MessageStore.h"
#include "Users.h"
using namespace king::test;

//UsersMessagesInterface<User,Message> x;
int main(int, const char* [])
{
	
	MessageStore store;;
	
	while (store.ProcessInput() == false){
	
	}
	
	store.terminate();
	
	return 0;
}
