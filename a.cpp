#include <iostream>

using namespace std;

int main()
{
	int a[10];
	int b = 10;
	int *c =&b;
	cout<<"sizeof(a)= "<<sizeof(a)<<endl; // 10 *4 = 40 
	cout<<"sizeof(a+1)= "<<sizeof(a+1)<<endl; // 4 ??
	cout<<"sizeof(*a)= "<<sizeof(*a)<<endl; // 4
	cout<<"sizeof(*a+1)= "<<sizeof(*a+1)<<endl; // 4
	cout<<"sizeof(a[0])= "<<sizeof(a[0])<<endl; //4 
	cout<<"sizeof(b)= "<<sizeof(b)<<endl; // 10 *4 = 40 
	cout<<"sizeof(b+1)= "<<sizeof(b+1)<<endl; // 4 ??
	cout<<"sizeof(c)= "<<sizeof(c)<<endl; // 10 *4 = 40 
	cout<<"sizeof(c+1)= "<<sizeof(c+1)<<endl; // 10 *4 = 40 
	cout<<"sizeof(*c)= "<<sizeof(*c)<<endl; // 10 *4 = 40 
	cout<<"sizeof(*c+1)= "<<sizeof(*c+1)<<endl; // 10 *4 = 40 
}
