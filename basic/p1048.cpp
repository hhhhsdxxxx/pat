#include <iostream>
#include <string>

using namespace std;

int main(){
	string A, B;
	cin >> A >> B;
	if(A.length() < B.length()){
		A = string(B.length()-A.length(), '0') + A;
	} else if(A.length() > B.length()){
		B = string(A.length() - B.length(), '0') + B;
	}
	//cout << A << " " << B << endl;
	int p = A.length()-1, i = 1;
	while(p >= 0){
		if(i & 0x00000001){
			int r = (A[p] - '0' + B[p] - '0') % 13;
			if(r < 10){
				B[p] = r + '0';
			} else if(r == 10){
				B[p] = 'J';
			} else if(r == 11){
				B[p] = 'Q';
			} else if(r == 12){
				B[p] = 'K';
			}
		} else {
			int r = (B[p] - A[p] + 10) % 10;
			B[p] = r + '0';
		}
		--p;
		++i;
	}
	cout << B;
	return 0;
}