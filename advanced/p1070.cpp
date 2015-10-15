#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct mooncake{
	// int t;
	double t, ap, tp;
	mooncake():t(0),ap(0.0){}
	mooncake(double tt):t(tt),ap(0.0){}
};

bool cmp(const mooncake &a, const mooncake &b){
	return a.ap > b.ap;
}

int main(int argc, char const *argv[]){
	int n, t;
	vector<mooncake> mk;
	cin >> n >> t;
	int k = n;
	while(k--){
		double at;
		cin >> at;
		mk.push_back(mooncake(at));
	}
	for(int i = 0; i < n; ++i){
		double tp;
		cin >> tp;
		mk[i].ap = tp/mk[i].t;
		mk[i].tp = tp;
	}
	sort(mk.begin(), mk.end(), cmp);
	double s = 0.0;
	k = 0;
	while(t > 0 && k < n){
		if(mk[k].t <= t){
			s += mk[k].tp;
			t -= mk[k].t;
			k++;
		}
		else {
			s += mk[k].ap*t;
			t = 0;
		}
		// cout << t << endl;
	}
	printf("%.2lf", s);
	return 0;
}