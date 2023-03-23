#include <iostream>
#include <map>
using namespace std;

int main()
{
	std::map<int,char> umap = {{1,'a'},{2,'b'}};
	// Access
	cout <<umap[1] << endl;
	cout << umap[2] << endl;

	// Update
	umap[1] = 'c';

	// Iterate
	for(auto& elm: umap) {
		std::cout << elm.first << " " << elm.second << " "<<endl;
	}
	cout << endl;

	// Find
	auto result = umap.find(2);
	if (result != umap.end()) {
		std::cout << "Found " << result->first << " " << result->second << '\n';
	} else {
		std::cout << "Not found\n";
	}

	return 0;
}
