#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct m_pair{
	int id, n;
	m_pair(int a, int b):id(a),n(b){}
};

void sign_price(double *deep, int *f, int i, double p, double r){
	if(fabs(deep[i]) < 0.00001){
		if(f[i] == -1)
			deep[i] = p;
		else {
			if(fabs(deep[f[i]]) < 0.00001)
				sign_price(deep, f, f[i], p, r);
			deep[i] = deep[f[i]]*(1.0+r/100);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, *f;
	double p, r, *deep;
	vector<m_pair> re;
	cin >> n >> p >> r;
	deep = new double[n];
	f = new int[n];
	for(int i = 0; i < n; ++i){
		f[i] = -1;
		deep[i] = 0.0;
	}
	for(int i = 0; i < n; ++i){
		int k, pt;
		cin >> k;
		if(k == 0){
			cin >> pt;
			re.push_back(m_pair(i, pt));
		}
		else{
			while(k--){
				cin >> pt;
				f[pt] = i;
			}
		}
	}
	double sum = 0.0;
	for(int i = 0; i < n; ++i)
		sign_price(deep, f, i, p, r);
	for(unsigned int i = 0; i < re.size(); ++i)
		sum += deep[re.at(i).id]*re.at(i).n;
	printf("%.1lf", sum);
	return 0;
}