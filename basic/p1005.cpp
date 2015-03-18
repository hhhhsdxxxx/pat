#include <iostream>

using namespace std;

int index(int n, int k, int *num){
	for(int i = 0; i < k; i++)
		if(num[i] == n)
			return i;
	return -1;	
}

int findmax_uncover(int k, int *map, int *num){
	int max = 0;
	int index = 0;
	for(int i = 0; i < k; i++){
		if(num[i] > max && map[i] == 0){
			index = i;
			max = num[i];
		}
	}
	map[index] = 1;
	return max;
}

void map_n(int n, int k, int *map, int *num){
	while(n != 1){
		if(n%2 == 1)
			n = (3*n+1)/2;
		else
			n /= 2;
		if(index(n, k, num) != -1)
			if(map[index(n, k, num)] == 0)
				map[index(n, k, num)] = 1;
			else
				break;
	}
}

int main(){
	int k;
	cin >> k;
	int *num, *map;
	map = new int[k];
	for(int i = 0; i < k; i++)
		map[i] = 0;
	num = new int[k];
	for(int i = 0; i < k; i++)
		cin >> num[i];
	for(int i = 0; i < k; i++)
		map_n(num[i], k, map, num);
	int re;
	int i = 0;
	while((re = findmax_uncover(k, map, num)) != 0){
		if(i == 0)
			cout << re;
		else
			cout << " " << re;
		i++;
	}
	return 0;
}