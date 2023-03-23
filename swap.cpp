#include <iostream>

using namespace std;

void swapByPointer (int *a,int *b)
{
	int temp =*a;
	*a = *b;
	*b=temp;
}

void swapByRefrence (int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main()
{
	int a=3,b=5;

	swapByPointer(&a,&b);
	cout<<a<<endl<<b<<endl;

	swapByRefrence(a,b);
	cout<<a<<endl<<b<<endl;
}
