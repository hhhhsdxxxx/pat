#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> su = {2};
bool f = 1;

bool is_su(long long n){
	if(n == 2)
		return 1;
	for(int i = 0; i < su.size() && su[i] < sqrt(n)+1; ++i)
		if(!(n%su[i]))
			return 0;
	if(f)
		su.push_back(n);
	return 1;
}

struct st{
	long long n, cnt;
	st(long long _n):n(_n),cnt(1){}
};

ostream& operator<<(ostream &ou, st &a){
	ou << a.n;
	if(a.cnt > 1)
		ou << "^" << a.cnt;
	return ou;
}

int main(){
	vector<st> ans;
	long long n;
	scanf("%lld", &n);
	long long p = 2;
	long long m = n;
	f = 0;
	while(n != 1 && p < sqrt(n)+1){
		if(is_su(p) && n%p==0){
			if(ans.empty() || p != ans.back().n)
				ans.push_back(st(p));
			else
				(ans[ans.size()-1].cnt)++;
			n /= p;
			f = 0;
		}
		else {
			++p;
			f = 1;
		}
	}
	if(n != 1) {
		if(ans.empty() || n != ans.back().n)
			ans.push_back(st(n));
		else
			(ans[ans.size()-1].cnt)++;
	}
	cout << m << "=";
	for(int i = 0; i < ans.size(); ++i){
		if(i)
			cout << "*";
		cout << ans[i];
	}
	if(m == 1)
		cout << "1";
	return 0;
}