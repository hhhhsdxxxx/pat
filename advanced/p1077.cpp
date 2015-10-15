#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> ms;
	string s, ans;
	ans = "";
	int n;
	cin >> n;
	getchar();
	while(n--){
		getline(cin, s);
		reverse(s.begin(), s.end());
		ms.push_back(s);
	}
	string tmp = ms.at(0);
	for(int i = 0; i < tmp.length(); ++i){
		bool r = true;
		for(int j = 1; j < ms.size(); ++j){
			if(ms.at(j).at(i) != tmp.at(i)){
				r = false;
				break;
			}
		}
		if(r)
			ans += tmp.at(i);
		else
			break;
	}
	if(ans == "")
		cout << "nai";
	else {
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	return 0;
}