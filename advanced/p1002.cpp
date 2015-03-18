/*
*浮点数判断不等于0，采用fabs(a) > eps(可允许误差)。
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	double expo[1001];
	for(int i = 0; i < 1001; i++)
		expo[i] = 0;
	int k, ex, cnt;
	double an;
	cnt = 0;
	cin >> k;
	while(k--){
		cin >> ex >> an;
		expo[ex] += an;
	}
	cin >> k;
	while(k--){
		cin >> ex >> an;
		expo[ex] += an;
	}
	for(int i = 0; i < 1001; i++)
		if(fabs(expo[i]) > 0.000001)
			cnt++;
	cout << cnt;
	for(int i = 1000; i >= 0; i--){
		if(fabs(expo[i]) > 0.000001){
			cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << expo[i]; 
		}
	}
	cout << endl;
	return 0;
}