#include <iostream>
#include <vector>

using namespace std;

struct sn{
	int m;
	bool r, l;
	sn():m(0),r(0),l(0){}
	bool right(){ return r && l; }
};

int main(){
	int N;
	cin >> N;
	vector<sn> num(N, sn());
	vector<int> ans;
	for(int i = 0; i < N; ++i)
		scanf("%d", &(num[i].m));
	int tmp = num[0].m;
	num[0].l = num[N-1].r = 1;
	for(int i = 1; i < N; ++i){
		if(num[i].m > tmp){
			tmp = num[i].m;
			num[i].l = 1;
		}
	}
	tmp = num.back().m;
	for(int i = N-2; i >= 0; --i){
		if(num[i].m < tmp){
			tmp = num[i].m;
			num[i].r = 1;
		}
	}
	for(int i = 0; i < N; ++i){
		if(num[i].right())
			ans.push_back(num[i].m);
	}
	if(ans.empty())
		puts("0");
	else {
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); ++i){
			if(i)
				cout << " ";
			cout << ans[i];
		}
	}
	cout << endl;
	return 0;
}