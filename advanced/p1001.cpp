#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	vector<char> v;
	cin >> a >> b;
	int c = a+b;
	int k = c;
	int cnt = 0;
	if(c != 0){
		while(k != 0){
			if(cnt%3 == 0 && cnt != 0)
				v.push_back(',');
			char ch = '0' + abs(k%10);
			v.push_back(ch);
			cnt++;
			k /= 10;
		}
		if(c < 0)
			v.push_back('-');
		for(vector<char>::iterator it = v.end()-1; it >= v.begin(); it--)
			cout << *it;
	}
	else
		cout << "0";
	return 0;
}