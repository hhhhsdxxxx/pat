#include <iostream>
using namespace std;

int main(){
	int n, cnt;

	cin >> n;
	cnt = 0;
	while(n != 1){
		if(n%2 == 1)
			n = (3*n+1)/2;
		else
			n /= 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}