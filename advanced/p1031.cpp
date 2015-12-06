#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n1, n2, n3, N;
	string in;
	cin >> in;
	N = in.length();
	n2 = (N+2)/3;
	n1 = (N+2-n2)/2;
	while(n1*2 != N+2-n2 || n1 > n2){
		++n2;
		n1 = (N+2-n2)/2;
	}
	// cout << n1 << n2 << endl;
	vector<vector<char>> mutrix(n1, vector<char>(n2, ' '));
	for(int i = 0; i < N; ++i){
		if(i < n1)
			mutrix[i][0] = in[i];
		else if(i < n1+n2-1)
			mutrix[n1-1][i-n1+1] = in[i];
		else
			mutrix[N-1-i][n2-1] = in[i];
	}
	// puts("Ok");
	for(int i = 0; i < mutrix.size(); ++i){
		for(int j = 0; j < mutrix[i].size(); ++j)
			printf("%c", mutrix[i][j]);
		puts("");
	}
	return 0;
}