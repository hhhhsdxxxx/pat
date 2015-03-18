#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	char ch;

	cin >> n >> ch;
	int k = 0;
	int remain = n+1;
	for(k = 1; k*2 <= remain; k += 2)
		remain -= 2*k;
	k -= 2;
	// cout << remain << endl;
	int l = k;
	for(; l >= (k+1)/2; l--){
		for(int j = 1; j <= l; j++){
			if(j <= (k-l))
				cout << " ";
			else
				cout << ch;
		}
		cout << endl;
	}
	for(l = (k+3)/2; l <= k; l++){
		for(int j = 1; j <= l; j++){
			if(j <= (k-l))
				cout << " ";
			else
				cout << ch;
		}
		cout << endl;
	}
	cout << remain;
	return 0;
}