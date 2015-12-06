#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string wordl[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string wordh[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int get_id(string &s, bool h){
	string *w;
	if(h)
		w = wordh;
	else
		w = wordl;
	for(int i = 0; i < 13; ++i)
		if(w[i] == s)
			return i;
	return -1;
}

void earth_to_mar(int n){
	int h = n/13, l = n%13;
	if(n == 0){
		puts("tret");
		return;
	}
	if(h)
		cout << wordh[h];
	if(h && l)
		cout << " ";
	if(l)
		cout << wordl[l];
	puts("");
}

void mar_to_earch(string &s){
	int l = s.find(' ');
	if(l == -1){
		int k = get_id(s, 0);
		if(k != -1)
			cout << k << endl;
		else
			cout << get_id(s, 1)*13 << endl; 
	}
	else {
		string hi = s.substr(0, l), lo = s.substr(l+1, s.length()-l-1);
		cout << get_id(hi, 1)*13+get_id(lo, 0) << endl;
	}
}

void parse(string &s){
	if(s[0] >= '0' && s[0] <= '9'){
		stringstream ss;
		int num;
		ss << s;
		ss >> num;
		earth_to_mar(num);
	}
	else
		mar_to_earch(s);
}

int main(){
	int N;
	cin >> N;
	getchar();
	while(N--){
		string s;
		getline(cin, s);
		parse(s);
	}
	return 0;
}