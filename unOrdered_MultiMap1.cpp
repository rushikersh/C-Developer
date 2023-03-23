#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	std::unordered_multimap<int , char >umm={{5,'d'}};
	umm.insert({1,'a'});
	umm.insert(std::pair<int ,char>(2,'b'));
	umm.insert(std::make_pair(3,'c'));
	umm.insert(std::make_pair(3,'c'));

//	typedef std::unordered_multimap<int , char>:: iterator umm1;
	auto umm it = umm.begin();
	for (umm it = umm.begin(); it!=umm.end(); it++)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	for (auto & it :umm)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	for (auto & elm: umm)
	{
		cout<<elm.first<<"  "<<elm.second<<endl;

	}
		return 0;
}
