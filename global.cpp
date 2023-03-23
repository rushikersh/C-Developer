#include <iostream>

using namespace std;

/*
 * int a;
void unsafe(int x) 
{
	x= 2; 
	a= 0; 
}
int main() 
{
	a= 1;
	unsafe(a); 
	printf("%d\n", a);  
}
*/
/*
static int a =2;
void add (int x)
{
	a=9;
	x= 10;
}

int main()
{
	a=1;
	add(a);
	cout<<"a = "<<a<<endl;
}
*/

int main()
{
	int a =9 ,b=4;

	a=a*b;
	b=a/b;
	a=a/b;
	cout<<a<<b<<endl;

	a=a+b;
	b=a-b;
	a=a-b;
	cout<<a<<b<<endl;

	a=a^b;
	b=a^b;
	a=a^b;
	cout<<a<<b<<endl;
}
