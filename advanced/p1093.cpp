#include <iostream>
#include <string>

using namespace std;

struct ptcnt{
	int p,t;
	ptcnt():p(0),t(0){}
};

int main(int argc, char const *argv[])
{
	string in;
	cin >> in;
	long long num = 0;
	int cnt[3] = {0};
	for(int i = 0; i < in.length(); i++){
		if(in.at(i) == 'A')
			cnt[1]++;
		else if(in.at(i) == 'P')
			cnt[0]++;
		else if(in.at(i) == 'T')
			cnt[2]++;
	}
	ptcnt a;
	a.t = cnt[2];
	for(int i = 0; i < in.length(); i++){
		if(in.at(i) == 'A'){
			num += a.p*a.t;
		}
		else if(in.at(i) == 'P'){
			a.p++;
		}
		else if(in.at(i) == 'T'){
			a.t--;
		}
	}
	cout << num%1000000007;
	return 0;
}