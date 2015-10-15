#include <iostream>
#include <map>

using namespace std;

// const int MROW = 800;
// const int MCOL = 600;

// int color[MROW][MCOL] = {0};

int main(){
	int m, n;
	cin >> m >> n;
	map<int, int> table;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j){
			int d;
			scanf("%d", &d);
			map<int, int>::iterator it = table.find(d);
			if(it != table.end())
				it->second++;
			else
				table.insert(pair<int, int>(d, 1));
		}
	int max = -1;
	int total = m*n;
	for(map<int, int>::iterator it = table.begin(); it != table.end(); ++it){
		if((it->second)<<1 > total){
			max = it->first;
			break;
		}
	}

	if(max != -1)
		cout << max;

	return 0;
}