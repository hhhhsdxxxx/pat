#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	int level;
	char ch;
	bool operator < (const node &A) const{
		return level < A.level;
	}
};

int main(int argc, char const *argv[])
{
	string sen_c, sen_r;
	cin >> sen_c >> sen_r;
	int word[2][27];
	int num[2][10];
	for(int i = 0; i < 27; i++){
		if(i < 10)
			num[0][i] = num[1][i] = -1;
		word[0][i] = word[1][i] = -1;
	}
	char ch1, ch2;
	for(unsigned int i = 0; i < sen_c.length(); i++){
		ch1 = sen_c.at(i);
		if(i < sen_r.length())
			ch2 = sen_r.at(i);
		if(ch1 != '_'){
			if((ch1-'A') < 0){
				if(num[0][ch1-'0'] == -1)
					num[0][ch1-'0'] = i;
			}
			else{
				if((ch1 - 'A') > 25){
					if(word[0][ch1-'a'] == -1)
						word[0][ch1-'a'] = i;
				}
				else{
					if(word[0][ch1-'A'] == -1)
						word[0][ch1-'A'] = i;
				}
			}
		}
		else{
			if(word[0][26] == -1)
				word[0][26] = i;
		}
		if(ch2 != '_' && i < sen_r.length()){
			if((ch2 - 'A') < 0){
				if(num[1][ch2-'0'] == -1)
					num[1][ch2-'0'] = i;
			}
			else{
				if((ch2 - 'A') > 25){
					if(word[1][ch2-'a'] == -1)
						word[1][ch2-'a'] = i;
				}
				else{
					if(word[1][ch2-'A'] == -1)
						word[1][ch2-'A'] = i;
				}
			}
		}
		else{
			if(ch2 == '_' && i < sen_r.length())
				if(word[1][26] == -1)
					word[1][26] = i;
		}
	}
	vector<node> v;
	for(int i = 0; i < 27; i++){
		if(i < 10)
			if(num[0][i] != -1 && num[1][i] == -1){
				node *p = new node;
				p->level = num[0][i];
				p->ch = '0'+i;
				v.push_back(*p);
			}
		if(word[0][i] != -1 && word[1][i] == -1){
			node *p1 = new node;
			p1->level = word[0][i];
			if(i != 26)
				p1->ch = 'A'+i;
			else
				p1->ch = '_';
			v.push_back(*p1);
		}
	}
	sort(v.begin(), v.end());
	for(vector<node>::iterator it = v.begin(); it < v.end(); it++)
		cout << it->ch;
	return 0;
}