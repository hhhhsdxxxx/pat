#include <iostream>

using namespace std;

struct str{
	int g, s, k;
	str(int _g, int _s, int _k):g(_g),s(_s),k(_k){}
	str():g(0),s(0),k(0){}
	str& operator+(const str &b){
		int rk = (k+b.k)%29;
		int l = (k+b.k)/29;
		int rs = (s+b.s+l)%17;
		l = (s+b.s+l)/17;
		int rg = g+b.g+l;
		str *r = new str(rg, rs, rk);
		return *r;
	}
};

ostream& operator<<(ostream &ou, str &a){
	ou << a.g << "." << a.s << "." << a.k << endl;
	return ou;
}

istream& operator>>(istream &in, str &a){
	scanf("%d.%d.%d", &a.g, &a.s, &a.k);
	return in;
}

int main(){
	str a, b;
	cin >> a >> b;
	cout << a+b;

	return 0;
}