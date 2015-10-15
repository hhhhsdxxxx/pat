#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct m_pair{
	int l, h;
	m_pair(int i, int j):l(i),h(j){}
};

vector<m_pair> ans;

int find(int p, int sum, vector<int> &value, int &re){
	if(value[p]-value[p-1] >= sum){
		re = p;
		return value[p]-value[p-1]-sum;
	}
	int l = p, r = (int)value.size(), m = (l+r)/2;
	while(l != m){
		if(value[m]-value[p-1] < sum)
			l = m;
		else if(value[m]-value[p-1] > sum)
			r = m;
		else {
			re = m;
			return 0;
		}
		m = (l+r)/2;
	}
	re = l+1;
	return (re<value.size())?(value[re]-value[p-1]-sum):-1;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> value(n+1, 0);
	for(int i = 1; i <= n; i++){
		int d;
		scanf("%d", &d);
		value[i] = value[i-1]+d;
	}
	int min = value[n]-value[0];
	for(int i = 1; i <= n; ++i){
		int p2;
		int r = find(i, m, value, p2);
		if(r <= min && r != -1){
			if(r < min){
				min = r;
				if(!ans.empty())
					ans.clear();
			}
			ans.push_back(m_pair(i, p2));
		}
	}
	// cout << value[11]-value[10] << endl;
	for(int i = 0; i < ans.size(); ++i)
		printf("%d-%d\n", ans[i].l, ans[i].h);
	return 0;
}