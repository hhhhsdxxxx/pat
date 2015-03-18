#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;

	int *r, *d;
	r = new int[N];
	d = new int[N];
	for(int i = 0; i < N; i++){
		r[i] = -1;
		d[i] = 1;
	}
	for(int i = 0; i < M; i++){
		int a, n;
		scanf("%d%d", &a, &n);
		while(n--){
			int b;
			scanf("%d", &b);
			r[b-1] = a-1;
		}
	}
	int max = 0;
	for(int i = 0; i < N; i++){
		int k = r[i];
		while(k != -1){
			d[i]++;
			k = r[k];
		}
		if(d[i] > max)
			max = d[i];
	}
	int *num = new int[max];
	for(int i = 0; i < max; i++)
		num[i] = 0;
	for(int i = 0; i < N; i++)
		num[d[i]-1]++;
	int index, m;
	index = m = 0;
	for(int i = 0; i < max; i++){
		if(num[i] > m){
			m = num[i];
			index = i;
		}
	}
	cout << num[index] << " " << index+1;
	return 0;
}