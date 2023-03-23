#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int a = 100;
	int * ptr =&a;

	cout<<*ptr<<endl;


	char  msgout[]="monday";
//	char * month = {"mon","feb" , "djfls;"};
	char * month = "mon";

	cout <<"strstr "<<strstr(msgout,month)<<endl;
	return 0;
}
