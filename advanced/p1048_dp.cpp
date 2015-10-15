#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10001;
const int MAXM = 101;

int dp[MAXN][MAXM];
bool u[MAXN][MAXM];

bool cmp(const int &a, const int &b){
	return a > b;
}

int cal(int n, int m, vector<int> &coin){
	memset(dp, 0, MAXN*MAXM*sizeof(int));
	memset(u, 0, MAXN*MAXM*sizeof(bool));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			int sec;
			if(coin[i]>j)
				sec = 0;
			else
				sec = dp[i-1][j-coin[i]]+coin[i];
			if(sec >= dp[i-1][j]){
				dp[i][j] = sec;
				u[i][j] = 1;
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][m];
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> coin(n+1, 0);
	for(int i = 1; i <= n; ++i)
		cin >> coin[i];
	sort(coin.begin()+1, coin.end(), cmp);
	int r = cal(n, m, coin);
	if(r == m){
		vector<int> ans;
		while(m){
			if(u[n][m]){
				m -= coin[n];
				ans.push_back(coin[n]);
			}
			n--;
		}
		for(int i = 0; i < ans.size(); ++i){
			if(i)
				cout << " ";
			cout << ans[i];
		}
	}
	else
		puts("No Solution");
	return 0;
}