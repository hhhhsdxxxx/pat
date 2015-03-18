#include <iostream>
#include <math.h>

using namespace std;

bool isSu(int n){
	if(n < 2)
		return false;
	else if(n == 2)
		return true;
	else{
		for(int i = 2; i < sqrt(n) + 1; i++)
			if(n%i == 0)return false;
	}
	return true;
}

int main(){
	int n, cnt;
	cin >> n;
	cnt = 0;
	for(int i = 2; i <= n; i++){
		if(isSu(i)){
			if(isSu(i+2) && i+2 <= n)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}