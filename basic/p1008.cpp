#include <iostream>

using namespace std;

void shift(int n, int *num){
	int temp;
	temp = num[n-1];
	for(int i = n-1; i >= 1; i--)
		num[i] = num[i-1];
	num[0] = temp;
}

int main(){
	int N ,M;
	cin >> N >> M;

	int num[100];
	for(int i = 0; i < N; i++)
		cin >> num[i];
	for(int i = 0; i < M; i++)
		shift(N, num);
	for(int i = 0; i < N; i++){
		if(i != 0) cout << " ";
		cout << num[i];
	}

	return 0;
}