#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	// vector<int> coin(n, 0);
	vector<int> cnt(1000, 0);
	bool r = 0;
	for(int i = 0; i < n; ++i){
		int d;
		cin >> d; 
		++cnt[d];
	}
	// sort(coin.begin(), coin.end());
	for(int i = 1; i <= m/2; ++i){
		--cnt[i];
		if(cnt[m-i] && cnt[i]){
			cout << i << " " << m-i << endl;
			r = 1;
			break;
		}
		++cnt[i];
	}
	if(!r)
		puts("No Solution");
	return 0;
}