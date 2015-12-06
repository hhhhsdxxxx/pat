#include <iostream>
#include <vector>

using namespace std;

int powern[22], sum = 0;
vector<int> ans, tmp;

int mypower(int n, int p){
	if(p <= 0)
		return 1;
	else
		return mypower(n, p-1)*n;
}

void dfs(int s, int l, int k, int ln){
	if(k == 0)
		return;
	for(int i = ln; i >= 1; --i){
		if(l-powern[i]-k+1<0)
			continue;
		tmp.push_back(i);
		dfs(s+i, l-powern[i], k-1, i);
		if(l == powern[i] && k == 1 && s+i>sum){
			ans = tmp;
			sum = s+i;
		}
		tmp.pop_back();
	}
}

int main(){
	int N, K, P;
	cin >> N >> K >> P;
	for(int i = 0; i < 22; ++i)
		powern[i] = mypower(i, P);
	int init = 1;
	while(powern[init]<N-K+1)
		init++;
	if(powern[init]>N-K+1)
		init--;
	dfs(0, N, K, init);
	if(ans.empty()){
		puts("Impossible");
		return 0;
	}
	cout << N << " = "; 
	for(int i = 0; i < ans.size(); ++i){
		if(i)
			cout << " + ";
		cout << ans[i] << "^" << P;
	}
	return 0;
}