#include <iostream>

using namespace std;

int add()
{
	return 0;
}

int main()
{
	printf("%p\n",add);
	printf("%u\n",add);
	printf("%d\n",add);

	cout<<endl;
	printf("%p\n",add());
	printf("%u\n",add());
	printf("%d\n",add());
}
