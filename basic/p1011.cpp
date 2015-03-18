#include <iostream>

using namespace std;

int sign(int n){
	if(n > 0)  return 1;
	else if(n < 0)  return -1;
	else if(n == 0) return 0;
	return 0;
}

int main(){
	int a, b, c, T, i;
	cin >> T;
	for(i = 1; i <= T; i++){
		cin >> a >> b >> c;
		if(sign(a)*sign(b) <= 0){
			cout << "Case #" << i << ": " << ((a+b) > c ? "true" : "false") << endl;
		}
		else{
			if(sign(a+b)*sign(a) < 0)
				cout << "Case #" << i << ": " << (sign(a) > 0 ? "true" : "false") << endl;
			else
				cout << "Case #" << i << ": " << ((a+b) > c ? "true" : "false") << endl;
		}
	}
	return 0;
}