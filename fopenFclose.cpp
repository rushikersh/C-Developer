#include <iostream>

using namespace std;

class A
{};

int main()
{
	A *a= new A;
	char arr[2048];
	FILE *fp = fopen("/tmp/a", "a+");

	if(fp)
	{
		cout<<"file open\n";
		fwrit""\sffofkne)
	}
	else 
	{
		cout<<"not open\n";
	}
//	fclose(fp);
//	delete a;
	return 0;
}
