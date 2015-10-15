#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int cnt[10];
	memset(cnt, 0, sizeof(int)*10);
	for(int i = 0; i < 10; ++i)
		cin >> cnt[i];
	int i;
	for(i = 1; i < 10; ++i){
		if(cnt[i]){
			cout << i;
			--cnt[i];
			break;
		}
	} 
	if(i == 10)
		puts("0");
	else {
		for(i = 0; i < 10; ++i){
			while(cnt[i]--)
				cout << i;
		}
	}

	return 0;
}