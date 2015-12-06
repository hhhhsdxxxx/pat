#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int N;
	cin >> N;
	vector<int> num(N, 0);
	for(int i = 0; i < N; ++i)
		cin >> num[i];
	sort(num.begin(), num.end(), cmp);
	int n(1), m(N), tn(2), tm(N/2);
	while(tn <= tm){
		if(N%tn == 0){
			m = tm;
			n = tn;
		}
		++tn;
		tm = N/tn;
	}
	vector<vector<int>> r(m, vector<int>(n, 0));
	int index = 0, i = 0, j = 0;
	while(index < N){
		r[i][j] = num[index++];
		if(j+1 < n && (i-1 < 0 || r[i-1][j]) && !r[i][j+1]){
			++j;
		} else if(i+1 < m && (j+1 >= n || r[i][j+1]) && !r[i+1][j]){
			++i;
		} else if(j-1 >= 0 && (i+1 >= m || r[i+1][j]) && !r[i][j-1]){
			--j;
		} else {
			--i;
		}
	}
	for(i = 0; i < m; ++i){
		for(j = 0; j < n; ++j){
			if(j)
				cout << " ";
			cout << r[i][j];
		}
		cout << endl;
	}
	return 0;
}