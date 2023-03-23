#include <iostream>

using namespace std;

void work()
{
	return ;
}

void test()
{
	return work();
}

int main()
{

	test ();
	int i =10;

	int &r=i;

	int *p=NULL;


}
