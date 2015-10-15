#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b){
	long long tmp;
	if(a == 0 || b == 0)
		return 0;
	if(a > b){
		tmp = a;
		a = b;
		b = tmp;
	}
	tmp = b%a;
	while(tmp){
		b = a;
		a = tmp;
		tmp = b%a;
	}
	return a;
}

struct num_dn{
	long long n, dn;

	friend ostream& operator<<(ostream &ou, num_dn &l);

	num_dn(long long a, long long b):n(a),dn(b){
		make_s();
	}

	void make_s(){
		if(n < 0){
			n = -n;
			dn = -dn;
		}
		long long k = gcd(abs(n), abs(dn));
		if(k != 0 && k != 1){
			n /= k;
			dn /= k;
		}
	}

	num_dn& operator=(num_dn &cp){
		n = cp.n;
		dn = cp.dn;
		return *this;
	}

	num_dn& operator+=(num_dn &add){
		if(add.n != 0){
			if(n == 0){
				*this = add;
			}
			else{
				n = n*add.dn+add.n*dn;
				dn *= add.dn;
				make_s();
			}
		}
		return *this;
	}


};

ostream& operator<<(ostream &ou, num_dn &l){
	if(l.n == 0){
		ou << "0";
	}
	else{
		if(l.n/l.dn != 0){
			ou << l.n/l.dn;
			if(l.n%l.dn != 0) 
				ou<< " " << abs(l.n%l.dn) << "/" << l.dn;
		}
		else
			ou << l.n%l.dn << "/" << l.dn;
	}
	return ou;
}

int main(int argc, char const *argv[])
{
	int N;
	bool f = true;
	long long a, b;
	cin >> N;
	num_dn *re;
	while(N--){
		scanf("%lld/%lld", &a, &b);
		if(f){
			re = new num_dn(a, b);
			f = false;
		}
		else {
			num_dn tmp(a, b);
			*re += tmp;
		}
	}
	cout << *re;
	return 0;
}