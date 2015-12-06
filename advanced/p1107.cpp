#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

unsigned int table[32] = { 
	0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020, 0x00000040, 0x00000080,
	0x00000100, 0x00000200, 0x00000400, 0x00000800, 0x00001000, 0x00002000, 0x00004000, 0x00008000,
	0x00010000, 0x00020000, 0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
	0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};

// struct group{
// 	int n;
// 	unsigned int p[32];
// 	group(int nn, int *pp){
// 		n = nn;
// 		memcopy(p, pp, sizeof(unsigned int) * 32);
// 	}

// 	bool is_same(int *_p){
// 		for(int i = 0; i < 32; ++i){
// 			if(p[i] & _p[i])
// 				return 1;
// 		}
// 		return 0;
// 	}

// 	bool is_same(group &a){
// 		for(int i = 0; i < 32; ++i){
// 			if(p[i] & a.p[i])
// 				return 1;
// 		}
// 		return 0;
// 	}

// 	void add(int *_p){
// 		++n;
// 		for(int i = 0; i < 32; ++i){
// 			p[i] |= _p[i];
// 		}
// 	}

// };


bool cmp(int a, int b){
	return a > b;
}

bool same(vector<unsigned int> &a, vector<unsigned int> &b){
	for(unsigned int i = 0; i < 32; ++i){
		if(a[i] & b[i])
			return 1;
	}
	return 0;
}

void dfs(int pos, vector<vector<int>> &r, vector<bool> &v, int &number){
	for(unsigned int i = 0; i < r[pos].size(); ++i){
		if(!v[r[pos][i]]){
			v[r[pos][i]] = 1;
			number++;
			dfs(r[pos][i], r, v, number);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<unsigned int>> person(n, vector<unsigned int>(32, 0));
	vector<vector<int>> relation(n, vector<int>());
	for(unsigned int i = 0; i < n; ++i){
		int k; 
		scanf("%d:", &k);
		while(k--){
			int p;
			scanf("%d", &p);
			person[i][p>>5] |= table[p & 0x0000001f];
		}
		for(int j = 0; j < i; ++j){
			if(same(person[i], person[j])){
				relation[i].push_back(j);
				relation[j].push_back(i);
			}
		}
	}
	vector<int> ans;
	vector<bool> is_visit(n, 0);
	int sum;
	for(unsigned int i = 0; i < n; ++i){
		if(!is_visit[i]){
			sum = 1;
			is_visit[i] = 1;
			dfs(i, relation, is_visit, sum);
			ans.push_back(sum);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	for(unsigned int i = 0; i < ans.size(); ++i){
		if(i)
			cout << " ";
		cout << ans[i];
	}
	// while(n--){
	// 	int k;
	// 	memset(_p, 0, 32 * sizeof(unsigned int));
	// 	scanf("%d: ", &k);
	// 	while(k--){
	// 		int p;
	// 		scanf("%d", &p);
	// 		_p[p >> 5] |= table[p & 0x0000001f];
	// 	}
	// 	if(ans.empty()){
	// 		ans.push_back(group(1, _p));
	// 	} else {
	// 		if(ans)
	// 	}
	// }
	// vector<group> ans;
	// sort(ans.begin(), ans.end(), cmp);
	// cout << ans.size() << endl;
	// for(unsigned int i = 0; i < ans.size(); ++i){
	// 	if(i)
	// 		cout << " ";
	// 	cout << ans[i].n;
	// }
	return 0;
}