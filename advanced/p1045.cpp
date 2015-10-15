#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXL = 10010;
const int MAXN = 210;

vector<vector<int>> dp(MAXN, vector<int>(MAXL, 0));
vector<int> row(MAXN, 0), col(MAXL, 0);

int cal(int n, int l){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= l; ++j){
			int tmp = (row[i]==col[j]);
			dp[i][j] = max(dp[i][j-1]+tmp, dp[i-1][j]+tmp);
		}
	}
	return dp[n][l];
}

int main(){
	int n, m, l;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> row[i];
	cin >> l;
	for(int i = 1; i <= l; ++i)
		cin >> col[i];
	cout << cal(m, l);
	return 0;
}