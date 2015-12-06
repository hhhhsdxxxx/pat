#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<double> num(n, 0.0);
	for(int i = 0; i < n; ++i)
		cin >> num[i];
	double sum = 0.0;
	for(int i = 0; i < n; ++i){
		sum += 1.0*(i+1)*(n-i)*num[i];
	} 
	printf("%.2lf", sum);
	return 0;
}