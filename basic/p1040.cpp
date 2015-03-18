#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string d;
	cin >> d;
	int p, t;
	p = t = 0;
	long long num = 0;
	for(int i = 0; i < d.length(); i++)
		if(d.at(i) == 'T')
			t++;
	for(int i = 0; i < d.length(); i++){
		if(d.at(i) == 'T')
			t--;
		else if(d.at(i) == 'P')
			p++;
		else if(d.at(i) == 'A')
			num += p*t;
	}
	cout << num%1000000007;
	return 0;
}