#include <iostream>

using namespace std;

class Base
{
	public :
		virtual void func() = 0;
/*		{
			cout<<"Base class\n";
		}
		*/
};

class Derived : public Base
{
	public :
		virtual void func()
		{
			cout<<"Derived class\n";
		}
};

class Child : public Base
{
	public :
		virtual void func()
		{
			cout<<"chlid class\n";
		}
};

class last : public Derived ,public Child
{
	public :
		virtual void func()
		{
			cout<<"last \n";
		}
};
int main()
{
	Derived d;
	Base &b=d;

	b.func();
}
