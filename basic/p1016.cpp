#include <iostream>

using namespace std;

int main(){
	char A[11], B[11];
	char a, b;
	cin >> A >> a >> B >> b;
	int re1, re2;
	re1 = re2 = 0;
	for(int i = 0; A[i] != 0; i++)
		if(A[i] == a)
			re1 = 10*re1 + a-'0';
	for(int i = 0; B[i] != 0; i++)
		if(B[i] == b)
			re2 = 10*re2 + b-'0';
	cout << re1 + re2;
	return 0;
}