#include <iostream>
#include <cstring>
#include <csignal>

using namespace std;

void signal_handle(int signal)
{
	printf("singnal receive -'%d'\n",signal);

	exit(signal);
}

int main()
{
	signal_handle(SIGABRT);

	abort();
}
