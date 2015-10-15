#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getsubs(string &s, int p){
	int len1 = 1, len2 = 0;
	int r = p+1, l = p-1;
	while(r<s.length() && l>=0){
		if(s[r] == s[l]){
			len1 += 2;
			++r;
			--l;
		}
		else
			break;
	}
	r = p+1;
	l = p;
	while(r<s.length() && l>=0){
		if(s[r] == s[l]){
			len2 += 2;
			++r;
			--l;
		}
		else
			break;
	}
	return max(len1, len2);
}

int main(){
	string s;
	getline(cin, s);
	int m = 1;
	for(int i = 0; i < s.length()-1; ++i){
		int r = getsubs(s, i);
		if(r > m)
			m = r;
	}
	cout << m;
	return 0;
}