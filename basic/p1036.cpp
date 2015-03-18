#include <iostream>

using namespace std;

int round(int n){
	return (n%2==0)?n/2:(n/2+1);
}

int main(int argc, char const *argv[])
{
	int N;
	char c;
	cin >> N >> c;
	for(int i = 0; i < round(N); i++){
		for(int j = 0; j < N; j++){
			if(i == 0 || i == round(N)-1)
				cout << c;
			else {
				if(j == 0 || j == N-1)
					cout << c;
				else
					cout << " ";
			}
		}
		if(i != round(N)-1)
			cout << endl;
	}
	return 0;
}