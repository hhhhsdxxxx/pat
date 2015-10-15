#include <iostream>
#include <string>

using namespace std;

bool isequal(string &s1, string &s2){
	int ptr = 0;
	while(ptr < s1.length() && ptr < s2.length()){
		if(s1[ptr] != s2[ptr])
			return false;
	}
	return true;
}

int change(string &s, int n){
	int p = 0, r = 0, ze = 0;
	bool digit = 0, zero = 0;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '.'){
			digit = 1;
			r = i;
			if(i == 1 && s[0] == '0')
				zero = 1;
			continue;
		}
		if(p >= n)
			s[i] = '0';
		if(zero && s[i] == '0')
			++ze;
		else {
			zero = 0;
			++p;
		}
	}
	if(!digit){
		r = p;
		s += '.';
	}
	while(p < n){
		s += '0';
		++p;
	}
	if(r < n)
		s = s.substr(0, n+1);
	else
		s = s.substr(0, r);
	if(s.length() > 2 && s[0] == '0' && s[1] == '.')
		return -ze;
	else
		return r;
}

void print(string &data, int n){
	cout << "0.";
	for(int i = 0; i < n; ++i)
		cout << data[i];
	cout << 
}

int main(){
	int n;
	string num1, num2;
	cin >> n >> num1 >> num2;
	return 0;
}