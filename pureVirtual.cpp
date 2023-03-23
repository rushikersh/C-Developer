#include <iostream>

using namespace std;

class Base 
{
	public :
	virtual void add() = 0;


};

void Base::add() 
{ 
	cout<<"add\n";
}

class Derived :public Base
{
	public :
	virtual	void add()
	{
		cout<<"Base\n";
	}
};
int main()
{
	Derived d;
	d.Base::add();
}
