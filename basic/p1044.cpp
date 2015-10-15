#include <iostream>

using namespace std;

int main(){
	int ip[4];
	for(int i = 0; i < 4; ++i){
		int k = 8, r = 0;
		while(k--)
			r = r*2+getchar()-'0';
		ip[i] = r;
	}
	printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	return 0;
}