#include <iostream>
#include <string>
#include <map>

using namespace std;

int p = 0;

bool isaw(char a){
	return a<='9'&&a>='0' || a<='Z'&&a>='A' || a<='z'&&a>='a';
}

void tolower(string &s){
	for(int i = 0; i < s.length(); ++i)
		if(s[i]<='Z'&&s[i]>='A')
			s[i] -= 'Z'-'z';
}

string getword(string &s){
	while(!isaw(s[p]) && p < s.length())p++;
	int i = p;
	while(isaw(s[p]) && p < s.length())p++;
	return i==p?"":s.substr(i, p-i);
}

int main(int argc, char const *argv[]){
	string sen;
	getline(cin, sen);
	tolower(sen);
	string s;
	map<string, int> word;
	while((s = getword(sen))!=""){
		// cout << s << endl;
		map<string, int>::iterator it = word.find(s);
		if(it == word.end())
			word.insert(pair<string, int>(s, 1));
		else
			(it->second)++;
	}
	int max = 0;
	string final;
	for(map<string, int>::iterator it = word.begin(); it != word.end(); ++it){
		if(it->second>max){
			max = it->second;
			final = it->first;
		}
		else if(it->second == max){
			final = (it->first < final)?it->first:final;
		}
	}
	cout << final << " " << max;
	return 0;
}