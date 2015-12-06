#include <iostream>

using namespace std;

int main(){
	int jia(0), yi(0);
	int a1, a2, b1, b2;
	int N;
	cin >> N;
	while(N--){
		cin >> a1 >> a2 >> b1 >> b2;
		if(((a1+b1) == a2) ^ ((a1+b1) == b2)){
			yi += (a1+b1) == a2;
			jia += (a1+b1) == b2;
		}
	}
	cout << jia << " " << yi;
	return 0;
}