#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b){
	long long tmp;
	if(a > b){
		tmp = a;
		a = b;
		b = tmp;
	}  // a < b
	tmp = b % a;
	while(tmp){
		b = a;
		a = tmp;
		tmp = b % a;
	}
	return a;
}

struct den{
	long long a, b;

	den(long long a1, long long b1){
		a = a1;
		b = b1;
		if(b < 0){
			b = -b;
			a = -a;
		}
		if(a1 != 0 && b1 != 0){
			long long k = gcd(abs(a1), abs(b1));
			a /= k;
			b /= k;
		}
	}
	friend ostream &operator<<(ostream &, den &);

	den& add(den &l){
		den *re = new den(a*l.b+b*l.a, b*l.b);
		return *re; 
	}

	den& sub(den &l){
		den *re = new den(a*l.b-b*l.a, b*l.b);
		return *re; 
	}

	den& mul(den &l){
		den *re = new den(a*l.a, b*l.b);
		return *re; 
	}

	den& div(den &l){
		den *re = new den(a*l.b, b*l.a);
		return *re; 
	}
};

ostream &operator<< (ostream &ou, den &l){
	if(l.a == 0)
		ou << "0";
	else{
		if(l.b == 0){
			ou << "Inf";
			return ou;
		}
		if(l.a < 0)
			ou << "(";
		if(l.a / l.b != 0)
			ou << l.a / l.b;
		if(l.a % l.b != 0){
			if(l.a / l.b != 0){
				cout << " ";
				ou << abs(l.a % l.b) << "/" << l.b;
			}
			else{
				ou << l.a % l.b << "/" << l.b;
			}
		}
		if(l.a < 0)
			ou << ")";
	}
	return ou;
}

int main(int argc, char const *argv[])
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	den op1(a1, b1), op2(a2, b2);
	cout << op1 << " + " << op2 << " = " << op1.add(op2) << endl
		<< op1 << " - " << op2 << " = " << op1.sub(op2) << endl
		<< op1 << " * " << op2 << " = " << op1.mul(op2) << endl
		<< op1 << " / " << op2 << " = " << op1.div(op2) << endl;
	return 0;
}