#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill_deep(int pos, vector<int> &d, vector<int> &t){
	if(d[pos] != -1)
		return;
	if(t[pos] == -1){
		d[pos] = 0;
	} else {
		if(d[t[pos]] == -1)
			fill_deep(t[pos], d, t);
		d[pos] = d[t[pos]]+1;
	}
}

int main(){
	int n;
	double price, rate;
	cin >> n >> price >> rate;
	vector<int> tree(n, -1);
	vector<int> retailers;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		if(k == 0)
			retailers.push_back(i);
		while(k--){
			int p;
			cin >> p;
			tree[p] = i;
		}
	}
	vector<int> deep(n, -1);
	for(int i = 0; i < n; ++i)
		fill_deep(i, deep, tree);
	vector<int> ans(1, retailers[0]);
	for(unsigned int i = 1; i < retailers.size(); ++i){
		if(deep[retailers[i]] < deep[ans[0]]){
			ans.clear();
			ans.push_back(retailers[i]);
		} else if(deep[retailers[i]] == deep[ans[0]]){
			ans.push_back(retailers[i]);
		}
	}
	for(int i = 0; i < deep[ans[0]]; ++i)
		price *= (1.0+rate/100.0);
	printf("%.4lf %u", price, ans.size());
	return 0;
}