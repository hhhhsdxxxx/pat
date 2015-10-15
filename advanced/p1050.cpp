#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	string original, del;
	getline(cin, original);
	getline(cin, del);
	set<char> cset;
	for(int i = 0; i < del.length(); ++i)
		cset.insert(del[i]);
	for(int i = 0; i < original.length(); ++i){
		if(cset.find(original[i]) == cset.end())
			cout << original[i];
	}
	return 0;
}