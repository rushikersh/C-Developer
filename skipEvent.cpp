#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() 
{
	char msgout[] ="\n;                  "; // Example message with only spaces
	{
		if ((msgout[0]==';'))
		{
			cout << "Message contains semi-colon." << endl;
		}
		if ((msgout[0]=='\n'))
		{
			cout << "Message Enter" << endl;
		}
		if ((msgout[0]==' ')) 
		{
			cout << "Message space" << endl;
		}
	}
	return 0;
}
