#include <iostream>

using namespace std;

int main()
{
	char a[10]= "madam";

//	scanf("%s",a);
	cin>>a;
	char temp;

	for (int i =0; i< 10;i++)
	{
		temp =a[i];
		int count =0;
		for(int j =0;j<10;j++)
		{
			if (temp == a[j])
			{
				count++;
			}
		}
		if(count == 1)
		{
			cout<<"Variable = "<<temp<<endl;
			return 0;
			}
	}
}
