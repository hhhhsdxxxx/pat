#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string in;
	getline(cin, in);
	vector<int> cnt(128, 0);
	for(unsigned int i = 0; i < in.length(); ++i)
		++cnt[in[i]];
	for(int i = 'a'; i <= 'z'; ++i)
		cnt[i] += cnt[i+'A'-'a'];
	int maxn = 0, index = 0;
	for(int i = 'a'; i <= 'z'; ++i){
		if(cnt[i] > maxn){
			index = i;
			maxn = cnt[i];
		}
	}
	cout << char(index) << " " << cnt[index] << endl;
	return 0;
}