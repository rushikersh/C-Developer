#include <iostream>
#include <cstring>

using namespace std;
int main() 
{

	const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

		char msgout[] = "22 Feb 2023;16:37:48;RUSHI-VB-212;192.168.2.212;root;10733;[C]winclient;0;eScan for Linux;Privacy Control Status;Privacy Control unavailable;winclient[5];";
//	char msgout[] = "2023;16:37:48;RUSHI-VB-212;192.168.2.212;root;10733;[C]                                                                                           ;	22 Feb 2023;16:37:48;RUSHI-VB-212;192.168.2.212;root;10733;[C]winclient;0;eScan for Linux;Privacy Control Status;Privacy Control unavailable;winclient[5];22 Feb 2023;16:37:48;RUSHI-VB-212;192.168.2.212;root;10733;[C]winclient;0;eScan for Linux;Privacy Control Status;Privacy Control unavailable;winclient[5];";
//char msgout[] = "eb 2023;16:37:48;RUSHI-VB-212;192.168.2.212;root;10733;[C]winclient;0;eScan for Linux;Privacy Control Status;Privacy Control unavailable;winclient[5];";
	if(strlen(msgout)>180)
		cout<<"pass\n";
	cout<<"strlen(msgout) = "<<strlen(msgout)<<endl;
	char a[2048];
	if(strstr(msgout,"[C]"))
	{
		strcpy(a,msgout);
		if ((msgout[0]==';'))
		{
			return 0;
		}
		if ((msgout[0]==' '))
		{
			return 0;
		}
		if ((msgout[0]=='\n'))
		{
			return 0;
		}
		if ((msgout[0]==':'))
		{
			return 0;
		}
		if((msgout[2]==' ')&&(msgout[6]==' '))
		{
		
		}
		else
		{
			cout<<"out\n";
			return 0;
		}
		char *token = strtok(a, ";");
/*		for (int i = 0; i < 12; i++) 
		{
			if (strstr(token, months[i]) != NULL) 
			{
			*/
		 for (const auto& month : months) {
			         if (strstr(token, month)) {
				// Check if the substring has the format "dd Mon yyyy"
				int day, year;
				char month[4];
				if (sscanf(token, "%d %s %d", &day, month, &year) == 3) 
				{
					std::cout << "Date found: " << token << std::endl;
					cout<<"msgout = "<<msgout<<endl;
					if(strstr(msgout,"\n\n") != NULL)
					{
						msgout[strlen(msgout)-1] = '\0';
						return 0;
					}
					else if (strstr(msgout,"\n") != NULL)
					{
						msgout[strlen(msgout)-1] = '\0';
						return 0;
					}
					else
					{
						return 0;
					}

					// Do something with the date here
					return 0;
				}
			}
		}
//		cout<<"msgout = "<<msgout<<endl;
		std::cout << "No date found." << std::endl;
	}
	return 0;
}
