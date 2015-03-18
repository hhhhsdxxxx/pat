//****坑人的地方：后面是正数而不是正整数***//
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct product{
	double d;
	double p;
	bool operator > (const product &A) const{
		double a = 1.0*p/d;
		double b = 1.0*A.p/A.d;
		return a>b;
	}
};

bool cmp(product a, product b){
	return a>b;
}

int main(int argc, char const *argv[])
{
	int N, D;
	cin >> N >> D;
	product *n = new product[N];
	for(int i = 0; i < N; i++)
		cin >> n[i].d;
	for(int i = 0; i < N; i++)
		cin >> n[i].p;
	sort(n, n+N, cmp);
	double profit = 0.0;
	double remain = 0;
	double total = double(D);
	int k = 0;
	while(total > 0 && k < N){
		total = total - n[k].d;
		remain = total;
		if(remain > 0){
			profit += n[k].p;
			k++;
		}
	}
	if(remain <= 0){
		remain += n[k].d;
		profit += 1.0*n[k].p*remain/n[k].d;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << profit;
	return 0;
}