#include <iostream>



int main()
{
		FILE *fp1;
		char str[] = "0";
                fp1 = fopen("./websites_allowed.txt", "a+");
		fwrite(str , 1 , sizeof(str) , fp1 );
		fwrite("\n", sizeof("\n"), 1, fp1);
		fwrite(str , 1 , sizeof(str) , fp1 );
		fclose(fp1);
}
