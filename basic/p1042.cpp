#include <iostream>

using namespace std;

int main(){
	int price;
	cin >> price;
	if(price < 8)
		cout << "count = 0\n";
	else {
		price -= 8;
		int cnt = 0;
		for(int i = price/5; i >= 0; --i){
			for(int j = (price-5*i)/2; j >= 0; --j){
				int k = price-5*i-2*j+1;
				printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i+1, j+1, k, i+j+k+2);
				cnt++;
			}
		}
		printf("count = %d\n", cnt);
	}
	return 0;
}