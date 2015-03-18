#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int *wscore = new int[N];
	for(int i = 0; i < N; i++)
		wscore[i] = -1;
	int num, score;
	int k = N;
	while(k--){
		cin >> num >> score;
		if(wscore[num-1] == -1)
			wscore[num-1] = 0;
		wscore[num-1] += score;
	}
	int max = -1;
	int index = -1;
	for(int i = 0; i < N; i++){
		if(wscore[i] > max){
			max = wscore[i];
			index = i+1;
		}
	}
	if(index != -1)
		cout << index << " " << max << endl;
	return 0;
}