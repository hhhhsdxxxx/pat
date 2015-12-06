#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> group(1000, 0);
	int n;
	cin >> n;
	while(n--){
		int g, p, score;
		scanf("%d-%d %d", &g, &p, &score);
		if(g < 1 || g > 1000 || p < 1 || p > 10 || score < 0 || score > 100)
			continue;
		group[g-1] += score;
	}
	int maxn = group[0], index = 0;
	for(int i = 1; i < 1000; ++i){
		if(group[i] > maxn){
			maxn = group[i];
			index = i;
		}
	}
	cout << index+1 << " " << group[index];
	return 0;
}