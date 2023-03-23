#include <iostream>

using namespace std;

int add (int *p)
{
	printf("%d\n",*p);
}

int main()
{
	int *p; // p doesn't initialize with any value 
	printf("%d\n");
	printf("%d\n",p);

//	add(p);
}
