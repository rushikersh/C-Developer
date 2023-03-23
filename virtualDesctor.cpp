#include <iostream>

using namespace std;

class D
{
	public :
		D() {cout<<"D ctor\n";}
		~D() {cout<<"~D dtor\n";}
//	virtual	~D() {cout<<"~D dtor\n";}
};
//class A : public D
class A
{
	public :
		A(){	cout<<"A ctor\n";}
//		~A(){	cout<<"~A dtor\n";}
	virtual	~A(){	cout<<"~A dtor\n";}

};
class B:public A,public D
{
	public :
		B() {cout<<"B ctor\n";}
		~B() {cout<<"~B dtor\n";}
//	virtual	~B() {cout<<"~B dtor\n";}
};
class C:public B
{
	public :
		C()	{cout<<"C ctor\n";}
		~C()	{cout<<"~C dtor\n";}
};
int main()
{
		A *a = new C;
		delete a;
}
