#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

///Removes spaces at right to the string.
/**
 * \param str String
 *
 * \return string
 */
char* strrtrim(char *str)
{
        int p;
	printf("%d\n",__LINE__);
	if(str != NULL)
	{
		p = strlen(str) - 1;
		printf("%d p='%d'\n",__LINE__,p);
		while(isspace(str[p]) && --p >= 0);
		{	printf("%d '%s'-> '%c'\n",__LINE__,str,str[p]);
			printf("%d p='%d'\n",__LINE__,p);
			str[++p] = '\0';
		}
	}
	printf("%d\n",__LINE__);
	return str;
}

int main()
{
	char  a[]="  fjdlj ";
	std::cout<<strrtrim((char *)a)<<std::endl;
	printf("'%s'\n",strrtrim((char *)a));

	return 0;
}
