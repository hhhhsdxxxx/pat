#include <iostream>

using namespace std;

int sign(long long a){
	if(a < 0)
		return -1;
	else if(a == 0)
		return 0;
	else
		return 1;
}

struct myi{
	long long a, b;
	myi(long long n):a(n/2),b(n%2){}
	myi& operator+=(myi &l){
		if(sign(a*2+b)*sign(l.a*2+l.b) == -1){
			a = a*2+b+l.a*2+l.b;
			b = a%2;
			a /= 2;
		}
		a = a+l.a+(b+l.b)/2;
		b = (b+l.b)%2;
		return *this;
	}
	bool operator>(myi &l){
		return (a!=l.a)?(a>l.a):(b>l.b);
	} 
};

bool tell(long long a, long long b, long long c){
	myi a1(a), b1(b), c1(c);
	a1 += b1;
	return a1 > c1;
}

int main(int argc, char const *argv[])
{
	int t, i = 0;
	cin >> t;
	long long a, b, c;
	while(t--){
		cin >> a >> b >> c;
		i++;
		if(tell(a, b, c))
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}

	return 0;
}