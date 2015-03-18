/*
std::getline
getline(cin, str);
*/

#include <iostream>
#include <string>

using namespace std;

int trs(char ch){
	if(ch >= 'A' && ch <= 'Z')
		return ch-'A';
	else if(ch >= 'a' && ch <= 'z')
		return ch-'a';
	else if(ch >= '0' && ch <= '9')
		return 26+ch-'0';
	else if(ch == '_')
		return 36;
	else if(ch >= '+' && ch <= '.')
		return 37+ch-'+';
	return -1;
}

int main(int argc, char const *argv[])
{
	string wrong, sentence;
	// cin >> wrong >> sentence;
	getline(cin, wrong);
	getline(cin, sentence);
	int word[41];
	for(int i = 0; i < 41; i++)
		word[i] = 1;
	for(unsigned int i = 0; i < wrong.length(); i++)
		if(trs(wrong.at(i)) != -1)
			word[trs(wrong.at(i))] = 0;
	for(unsigned int i = 0; i < sentence.length(); i++){
		if(word[37] == 0){
			if(sentence.at(i) < 'A' || sentence.at(i) > 'Z'){
				if(trs(sentence.at(i)) != -1)
					if(word[trs(sentence.at(i))] == 1)
						cout << sentence.at(i);
			}
		}
		else{
			if(trs(sentence.at(i)) != -1)
				if(word[trs(sentence.at(i))] == 1)
					cout << sentence.at(i);
		}
	}
	cout << endl;
	return 0;
}