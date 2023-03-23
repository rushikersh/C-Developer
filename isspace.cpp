// CPP program to count white spaces in a string
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// function to calculate whitespaces
void space(string& str)
{
	int count = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		int c = str[i];
		if (isspace(c))
			count++;
	}
	cout <<"space = "<<count;
}

char* strltrim(char *str)
{
	unsigned int p = 0;
	if(str != NULL)
	{
		while(isspace(str[p++]) && p < strlen(str));
		{	if(str[p] == '\0' && isspace(str[p - 1]))
			str[0] = 0;
			else if(--p > 0)
			{	
				printf("str='%s'\t p='%d'\tstr+p='%s'\t strlen(str)='%d'\n",str,p, str + p, strlen(str));
				printf("strlen(str)='%d'\tstrlen(str+p)='%d'\n",strlen(str),strlen(str+p));
				//			strncpy(str, str + p, strlen(str));
				strcpy(str, str + p);
				printf("str='%s'\n",(str));
			}
		}
	}

	return str;
}
char* strrtrim(char *str)
{
	int p;
	if(str != NULL)
	{
		p = strlen(str) - 1;
		while(isspace(str[p]) && --p >= 0);
		str[++p] = 0;
	}
	return str;
}

// Driver Code
int main()
{
	string str = "   Geeks for\t\n\v\f\r geeks";
	cout<<"22->"<<isspace(str[22])<<endl;  
	cout<<"21->"<<isspace(str[21])<<endl;
	cout<<"20->"<<isspace(str[20])<<endl; //at whitespace it return non-zero value 22->0
	/*
	   22->0
	   21->0
	   20->0
	   16->0 // otherwise it retrun 0;
	   15->0
	   14->8192 //accept character isspace(character) at whitespace it return non-zero value 8192;
	   13->8192
	   12->8192
	   11->8192
	   10->8192
	   9->8192
	   6->0
	   5->8192
	   4->0
	   */
	cout<<"16->"<<isspace(str[16])<<endl;
	cout<<"15->"<<isspace(str[15])<<endl;
	cout<<"14->"<<isspace(str[14])<<endl;
	cout<<"13->"<<isspace(str[13])<<endl;
	cout<<"12->"<<isspace(str[12])<<endl;
	cout<<"11->"<<isspace(str[11])<<endl;
	cout<<"10->"<<isspace(str[10])<<endl;
	cout<<"9->"<<isspace(str[9])<<endl;
	cout<<"6->"<<isspace(str[6])<<endl;
	cout<<"5->"<<isspace(str[5])<<endl;
	cout<<"4->"<<isspace(str[4])<<endl;
	space(str);
	cout<<"\nstr = '"<<str<<"'"<<endl;
	cout<<"strlen(str) = "<<str.length()<<endl;
	char s1[] = "   Geeks for geeks      ";
	std::cout<<"strrtrim ->'"<<strrtrim(s1)<<"'"<<std::endl;
	char s2[] = "   Geeks for geeks      ";
	printf("strltrim ->'%s'\n",strltrim(s2));
	return 0;

}
