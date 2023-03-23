#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	char msgout[]="01 Mar 2023;12:11:12;ESCAN-HP-LAPTOP-15-BS0XX;$$$$$$$$$$$$$$$;root;10800;[C]winclient;0;eScan for Linux;Software Install/Uninstall Status;New Software Installed [13/Feb/2023] [13/02/2023] {Ver:2:8.2.3995-1ubuntu2.3};Vim;";
//	char msgout[]="01 Mar 2023;12:11;";
	int count =0;
//	int colonCount =std::count(std::begin(msgout), std::end(msgout), ':');
	int colonCount =0;
	 for (int i = 0; msgout[i] != '\0'; i++) {
	         if (msgout[i] == ':') {
		            colonCount++;
		           }
         }		 
	cout<<"colon count = "<<colonCount<<endl;
	if(colonCount <2 )
	{
		return 0;
	}
	
	char *pch = strchr(msgout,';');
	while(pch != NULL)
	{
	cout<<"pch = "<<pch<<endl;
		count ++;
		pch = strchr(pch+1,';');
	}
	if (count == 12)
		cout<<"the string present\n";
	else
		cout<<"string not present\n";

	cout<<"msgout = "<<msgout<<endl;
	return 0;
}
