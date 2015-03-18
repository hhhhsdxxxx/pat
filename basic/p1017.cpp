#include <iostream>

using namespace std;

int main(){
	char num[1001];
	int a;
	cin >> num >> a;
	char re[1001] = {0};
	int rey = 0;
	for(int i = 0; num[i] != 0; i++){
		rey = 10*rey + num[i] - '0';
		re[i] = rey/a + '0';
		rey = rey%a;
	}
	if(re[0] == '0' && re[1] != 0)
		cout << re+1 << " " << rey;
	else
		cout << re << " " << rey;

}