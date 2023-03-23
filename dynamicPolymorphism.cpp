#include <iostream>

using namespace std;

class Base 
{
	public :
		virtual void fun ()
		{
			cout<<"Inside base class\n";
		}
};

class Child : public Base 
{
	public :
		void fun ()
		{
			cout<<"child class \n";
		}
};
int main()
{
/*	Base *b = new Child;
	b->fun();
*/

/*	Child c ;
	Base &b = c;
*/
	int a =9;

	int &c = a;
	
	c=a;
	cout<<c<<endl;
	cout<<a<<endl;
	cout<<&c<<endl;
	cout<<&a<<endl;
//	cout<<*c<<endl;

	int *b =&a;
	int *d =NULL;
	
	*b =a;
	cout<<b<<endl;
	cout<<&b<<endl;
	cout<<*b<<endl;

//	b.fun();
}
