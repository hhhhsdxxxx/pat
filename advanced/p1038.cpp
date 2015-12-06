#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


bool cmp(const string& a, const string& b){
	return a+b < b+a;
}

// bool notzero(char c){
// 	return c != '0';
// }

// int get_first(string &s){
// 	string::iterator it = find_if(s.begin(), s.end(), notzero);
// 	if(it == s.end())
// 		return 0;
// 	else
// 		return *it-'0';
// }

int main(){
	int n;
	cin >> n;
	vector<vector<string>> num(10, vector<string>());
	// vector<bool> u(n, 0);
	for(int i = 0; i < n; ++i){
		string in;
		cin >> in;
		num[in[0]-'0'].push_back(in);
	}
	for(int i = 0; i < 10; ++i)
		sort(num[i].begin(), num[i].end(), cmp);
	string ans = "";
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < num[i].size(); ++j){
			if(!i && ans == ""){
				stringstream ss, ss2;
				ss << num[i][j];
				int di;
				ss >> di;
				ss2 << di;
				if(di){
					string s;
					ss2 >> s;
					ans += s;
				}
			}
			else
				ans += num[i][j];
		}
	}
	if(ans == "")
		cout << "0";
	else
		cout << ans;
	return 0;
}