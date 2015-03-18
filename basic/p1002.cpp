#include <iostream>

using namespace std;

void print_pingyin(int n){
	switch(n){
		case 0: cout << "ling"; break;
		case 1: cout << "yi"; break;
		case 2: cout << "er"; break;
		case 3: cout << "san"; break;
		case 4: cout << "si"; break;
		case 5: cout << "wu"; break;
		case 6: cout << "liu"; break;
		case 7: cout << "qi"; break;
		case 8: cout << "ba"; break;
		case 9: cout << "jiu"; break;
		default: break;
	}
}

int tenpow(int n){
	if(n < 0) return -1;
	if(n == 0)return 1;
	return 10 * tenpow(n-1);
}

void print_info(int n){
	int i, cnt;

	cnt = 0;
	i = n;
	while((i = i/10) != 0)
		cnt++;
	i = n;
	while(cnt != -1){
		int k = tenpow(cnt);
		if(i != n)
			cout << " ";
		print_pingyin(i/k);
		i = i % k;
		cnt--;
	}
}

int main(){
	char num[101];
    int sum;

	cin >> num;
	sum = 0;
	for(int i = 0; num[i] != 0; i++)
		sum += num[i] - '0';
	print_info(sum);
	return 0;
}