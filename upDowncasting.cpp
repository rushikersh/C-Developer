#include <iostream>

using namespace std;

class Parent 
{
	public:
		void sleep()
	       	{
			cout<<"sleep\n";
		}
		virtual ~Parent(){}
};

class Child: public Parent 
{
	public:
		void gotoSchool()
		{
			cout<<"gotoSchoool\n";
		}
};

int main( ) 
{ 
	Parent parent;
/*	Child child;

	// upcast - implicit type cast allowed
	Parent *pParent = &child; 

	// downcast - explicit type case required 
	Child *pChild =  (Child *) &parent;
	Parent *p=new Child;*/
	Child *child = (Child *)(&parent);
	Child * c= dynamic_cast<Child *>(&parent);
/*	pParent -> sleep();
//	pParent -> gotoSchool();
	pChild -> sleep();
	pChild -> gotoSchool();
*/
	return 0; 
}
