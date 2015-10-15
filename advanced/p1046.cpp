#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, total_len = 0;
	cin >> n;
	vector<int> x(n+1, 0);
	int p = 0;
	while(n--){
		int d;
		scanf("%d", &d);
		x[++p] = total_len+d;
		total_len = x[p]; 
	}
	cin >> n;
	while(n--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b)
			swap(a, b);
		// cout << x[a-1] << " " << x[b-1] << endl;
		printf("%d\n", min(total_len-(x[b-1]-x[a-1]), x[b-1]-x[a-1]));
	}
	return 0;
}