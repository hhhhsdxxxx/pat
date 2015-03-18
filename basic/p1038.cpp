#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int score[101] = {0};
	int N;
	cin >> N;
	while(N--){
		int s;
		cin >> s;
		score[s]++;
	}
	cin >> N;
	while(N--){
		int n;
		cin >> n;
		if(N==0)
			cout << score[n];
		else
			cout << score[n] << " ";
	}
	return 0;
}