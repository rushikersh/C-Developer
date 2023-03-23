#include <string>  
#include <cstring>  
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
using namespace std;
int main()
{
	char filename[100];
	cin>>filename;

	std::string command("file ");

	command = command + filename + " 2>&1";
	std::array<char, 128> buffer;
	std::string result;

	std::cout << "" <<command<< std::endl;
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return 0;
	}
	while (fgets(buffer.data(), 128, pipe) != NULL) 
	{
		result += buffer.data();
	}
	auto returnCode = pclose(pipe);

	char *sub = strstr((char*)result.c_str(), ":");
	cout<<sub<<endl;

	{
		char *substring = strstr(sub, "text");	
		if(substring)
		{
			cout<<"Text\n";
		}
	}

	{
		char *substring = strstr(sub, "object");	
		if(substring)
		{
			cout<<"object\n";
		}
	}

	std::cout << result << std::endl;
//	std::cout << returnCode << std::endl;

	return 0;
}
