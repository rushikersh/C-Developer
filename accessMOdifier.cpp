#include <iostream>
using namespace std;

class A
{
	protected:
		int x=1;
	public:
		void setX(int i) { x = i; }
		void set() { cout<<this->x<<endl; }
};

class B : public A
{
	public:
		void display() { cout << "x = " << x << endl; }
};

class C : private A
{
	public:
		void display() { cout << "x = " << x << endl; }
};

int main()
{
	A a;
	a.set();
	B b;
	b.setX(10);
	b.display();
/*
	C c;
	c.setX(20);
	c.display();
*/
	return 0;
}
