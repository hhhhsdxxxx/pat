/*
第一次循环考虑大多数的情况。
第二次直接从会大于该种情况的地方进行判断
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, p;
	cin >> N >> p;
	int *num = new int[N];
	int k = N;
	while(k--)
		cin >> num[k];
	sort(num, num+N);
	int max = 0;
	for(int i = 0; i < N; i++){
		for(int j = i+max; j < N; j++){
			if(num[j]/num[i] > p || (num[j]/num[i] == p && num[j]%num[i] != 0))
				break;
			if((j-i+1) > max)
				max = j-i+1;
		}
	}
	cout << max;
	return 0;
}