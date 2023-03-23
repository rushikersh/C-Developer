#include <iostream>

using namespace std;

int main()
{
	int a[8]={1,11,2,12,3,13,4};
	int temp = 11,flag;
	for (int i =0;i<8;)
	{
		if (temp = a[i])
			flag = 1;
		i=i+2;
	}
	for (int i =1;i<8;)
	{
		if (temp = a[i])
			flag = 1;
		i=i+2;
	}
	if (flag) 	
		cout<<"print"<<endl;
	else
		cout<<"11 false"<<endl;

	return 0;
}
