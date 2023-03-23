#include <iostream>

class B
{
	public : 
		virtual ~ B() {}
};

class D : public B
{

};

int main()
{
	B *a =  new D;
	D *b3=dynamic_cast<D*>(a);
}
