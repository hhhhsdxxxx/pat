#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;

bool cmp(const vector<int> &a, const vector<int> &b){
	int p = 0;
	while(p < a.size() && p < b.size()){
		if(a[p] != b[p])
			return a[p] > b[p];
		p++;
	}
	return a.size() > b.size();
}

void get_s(int pos, int s, vector<int> &p, vector<int> &w){
	int re = 0;
	vector<int> path;
	while(pos != -1){
		re += w[pos];
		path.push_back(w[pos]);
		pos = p[pos];
	}
	if(!path.empty())
		reverse(path.begin(), path.end());
	if(re == s)
		ans.push_back(path);
}

int main(){
	int n, m, s;
	cin >> n >> m >> s;
	set<int> leaf;
	vector<int> wei(n, 0), path(n, -1);
	for(int i = 0; i < n; ++i){
		leaf.insert(i);
		cin >> wei[i];
	}
	while(m--){
		int f, k, ch;
		cin >> f >> k;
		while(k--){
			cin >> ch;
			// cout << ch << endl;
			path[ch] = f;
		}
		leaf.erase(f);
	}
	for(set<int>::iterator it = leaf.begin(); it != leaf.end(); ++it){
		// cout << *it << endl;
		get_s(*it, s, path, wei);
	}
	sort(ans.begin(), ans.end(), cmp);
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			if(j)
				cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}