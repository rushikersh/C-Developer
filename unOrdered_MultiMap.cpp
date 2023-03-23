#include <bits/stdc++.h>
using namespace std;

typedef unordered_multimap<string , int >::iterator unit;

void printUmm(unordered_multimap<string , int> umm)
{

	for(unit it = umm.begin(); it!= umm.end();it++)
	{
		cout<<"< "<<it->first<<" , "<<it->second<<"> "<<endl;
	}
}

int main()
{
	unordered_multimap<string , int>umm1;

	unordered_multimap<string , int>umm2(
			{{"apple",1},
			{"ball",2},
			{"apple",3},
			{"cat",4},
			{"dog",5},
			{"cat",9},
			{"apple",7}


			});

	umm1=umm2;
	printUmm(umm1);

	if (umm2.empty())
		cout<<"unordered multimap is empty \n";
	else
		cout<<"not empty\n";
	
	cout<<"size = "<<umm1.size()<<endl;

	string key = "apple";
	unit it = umm1.find (key);
//	if(it ! = umm1.end())
		cout<<"";

	return 0;

}
