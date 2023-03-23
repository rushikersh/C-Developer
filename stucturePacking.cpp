#include <iostream>
#include <cstring>
using namespace std;

#pragma pack(1)
#define print(b) cout<<#b<<":"<<(b?"true":"false")<<endl;
//#define print(b) printf("%s : %s\n", #b, (b ? "TRUE" : "FALSE"))
class Base
{
	char a;
//	char b;
//	char d;
//	short c;
	int c;
};
int main()
{
	Base b;
	cout<<"size of Base = "<<sizeof(b)<<endl;
	cout<<"size of Base = "<<sizeof(int)<<endl;
	bool x= true;
	print(x);
}
