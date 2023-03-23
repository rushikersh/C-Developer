#include <iostream>
#include <stdio.h>

using namespace std;
/*
struct A
{
	int x; // 4
	double y; // 8	
};

struct B
{
	int y; // 4
	double x; // 8	
	A a; // 16
};
*/
class X
{
	int a;//4
	double b;//8
};

class Y
{
	int b;//4
	char c;
	char c;
	char c;
	X a; //16
//	int y;
};
int main()
{
//	cout<<"sizeof(B) ="<<sizeof(B)<<endl;
	cout<<"sizeof(X) ="<<sizeof(X)<<endl;
	cout<<"sizeof(Y) ="<<sizeof(Y)<<endl;
	return 0;
}
