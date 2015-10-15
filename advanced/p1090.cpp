#include <iostream>
#include <cmath>

using namespace std;

void price(int *mem, double *_price, int i, double p, double r){
	if(mem[i] == -1)
		_price[i] = p;
	else{
		int k = mem[i];
		if(k == -1)
			_price[i] = p*(1.0+r/100);
		else{
			if(_price[k] >= 0)
				_price[i] = _price[k]*(1.0+r/100);
			else{
				price(mem, _price, k, p, r);
				_price[i] = _price[k]*(1.0+r/100);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, *member;
	double p, r, *_price;
	cin >> N >> p >> r;
	member = new int[N];
	_price = new double[N];
	for(int i = 0; i < N; ++i){
		cin >> member[i];
		_price[i] = -1;
	}
	double max = p;
	int cnt = 0;
	for(int i = 0; i < N; ++i)
		price(member, _price, i, p, r);
	for(int i = 0; i < N; ++i){
		if(_price[i] > max){
			max = _price[i];
			cnt = 1;
		}
		else if(fabs(_price[i]-max)<0.000001)
			cnt++;
	}
	printf("%.2lf %d\n", max, cnt);
	return 0;
}