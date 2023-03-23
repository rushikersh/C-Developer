#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
using namespace std;

int dup (string str)
{
	const char * s=str.c_str();
	char temp;
	int j=0,count=0;
	for(int i=0;i<strlen(s);i++)
	{
		temp=s[j];
		if(temp==s[i])
			count++;

		if(count==2)
		{
			printf("%s %c\n",str.c_str(),temp);
			break;
		}
		j++;
	}
	return 0;
}
int main()
{
	cout<<dup("capability")<<endl;
	return 0;
}

