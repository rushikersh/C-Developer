#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int number =3;
	int bit = 2;
	cout<<"(1<<bit) ="<<(1<<bit)<<endl;
//	number |= (1<<bit);
	number =number |  (1<<bit);
	cout<<"number ="<<number<<endl;

	number =3;
	int bitPos = 1;

	int bit1 =(number >> bitPos) & 1;
	cout<<bitPos<<" position bit "<<bit1<<endl;

	number = 3;
	cout<<"(number >>1)"<<(number >>1)<<endl;
	cout<<"(number <<1)"<<(number <<1)<<endl;
	return 0;
	11
	100
	101
	110
}
