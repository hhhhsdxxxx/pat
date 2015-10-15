#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


/*****time full******/
// bool isfind = false;
// int N, M;

// void find_ans(vector<int> &ans, int *p, bool *u, int s){
// 	for(int i = 0; i < N; ++i){
// 		if(isfind)
// 			break;
// 		if(!u[i]){
// 			if(s+p[i] < M){
// 				u[i] = true;
// 				ans.push_back(p[i]);
// 				find_ans(ans, p, u, s+p[i]);
// 				if(!isfind){
// 					u[i] = false;
// 					ans.pop_back();
// 				}
// 			}
// 			else if(s+p[i] > M)
// 				break;
// 			else {
// 				isfind = true;
// 				u[i] = true;
// 				ans.push_back(p[i]);
// 				for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
// 					if(it != ans.begin())
// 						cout << " ";
// 					cout << *it;
// 				}
// 				cout << endl;
// 				exit(0);
// 			}
// 		}
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	int *p;
// 	bool *u;
// 	cin >> N >> M;
// 	p = new int[N];
// 	u = new bool[N];
// 	for(int i = 0; i < N; ++i){
// 		cin >> p[i];
// 		u[i] = false;
// 	}
// 	sort(p, p+N);
// 	vector<int> ans;
// 	find_ans(ans, p, u, 0);
// 	if(ans.empty())
// 		cout << "No Solution\n";
// 	else {
// 		for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
// 			if(it != ans.begin())
// 				cout << " ";
// 			cout << *it;
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }

/****dp****/
const int MAXSIZE = 10001;
const int MAXPRICE = 101;

int dp[MAXSIZE][MAXPRICE];
bool u[MAXSIZE][MAXPRICE];
int *num;

int cal(int n, int m){
	memset(dp, 0, sizeof(int)*(n+1)*(m+1));
	memset(u, false, sizeof(bool)*(n+1)*(m+1));

	for(int i = 1; i < n+1; ++i){
		int sec;
		for(int j = 1; j <= m; ++j){
			if(j-num[i]<0)
				sec = 0;
			else
				sec = dp[i-1][j-num[i]]+num[i];
			if(dp[i-1][j] > sec)
				dp[i][j] = dp[i-1][j];
			else {
				u[i][j] = true;
				dp[i][j] = sec;
			}
		}
	}

	return dp[n][m];
}

bool cmp(const int &a, const int &b){
	return a > b;
}

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	num = new int[N+1];
	memset(num, 0, sizeof(int)*(N+1));

	for(int i = 1; i < N+1; i++)
		cin >> num[i];

	sort(num+1, num+N+1, cmp);
	int re = cal(N, M);
	int m = M, n = N;
	if(re == M){
		while(m){
			while(!u[n--][m]);
			if(m != M)
				cout << " ";
			cout << num[n+1];
			m -= num[n+1];
		}
	}
	else {
		cout << "No Solution";
	}

	return 0;
}