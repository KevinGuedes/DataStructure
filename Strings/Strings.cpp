#include <iostream>
using namespace std;

int main()
{
	char names[2][13] = { "123456789", "kevin guedes" }, another[13] = "arthur", t[13]; //the only place where it can receive a value
	//another = names[0]; //wont work
	//names[0] = another; //wont work
	//names[0] = "uhuuuuu"; //wont work
	cout << "Initial Name #0: " << names[0] << endl;
	strcpy_s(names[0], another);
	cout << "Changed Name #0: " << names[0] << endl;

	char test[10] = "kevin";
	cout << test << endl;
}

