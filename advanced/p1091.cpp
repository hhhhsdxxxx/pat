#include <iostream>

using namespace std;

int cnt = 0;

int _dfs(bool *sign, int *val, int i, int M, int N, int L){
	int re = 1;
	sign[i] = true;
	if((i%N+1)<N && !sign[i+1] && val[i+1] == 1)
		re += _dfs(sign, val, i+1, M, N, L);
	if((i%N-1)>=0 && !sign[i-1] && val[i-1] == 1)
		re += _dfs(sign, val, i-1, M, N, L);
	if((i-N)>=0 && !sign[i-N] && val[i-N] == 1)
		re += _dfs(sign, val, i-N, M, N, L);
	if((i+N)<M*N*L && !sign[i+N] && val[i+N] == 1)
		re += _dfs(sign, val, i+N, M, N, L);
	if((i-M*N)>=0 && !sign[i-M*N] && val[i-M*N] == 1)
		re += _dfs(sign, val, i-M*N, M, N, L);	
	if((i+M*N)<M*N*L && !sign[i+M*N] && val[i+M*N] == 1)
		re += _dfs(sign, val, i+M*N, M, N, L);
	return re;
}

void dfs(bool *sign, int *val, int M, int N, int L, int T){
	for(int i = 0; i < M*N*L; ++i){
		if(!sign[i]){
			int k = 0;
			if(val[i]){
				k = _dfs(sign, val, i, M, N, L);
			}
			else{
				sign[i] = true;
				k = 0;
			}
			if(k >= T)
				cnt += k;
		}
	}
}



int main(int argc, char const *argv[]){
	int M, N, L, T;
	cin >> M >> N >> L >> T;
	bool *sign = new bool[M*N*L];
	int *val = new int[M*N*L];
	for(int i = 0; i < M*N*L; ++i){
		cin >> val[i];
		sign[i] = false;
	}
	dfs(sign, val, M, N, L, T);
	cout << cnt << endl; 
	return 0;
}