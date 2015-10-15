#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int get_num(int *p){
	return p[0]*1000+p[1]*100+p[2]*10+p[3];
}

int rev(int n){
	int op1[4], op2[4];
	for(int i = 3; i >= 0; --i){
		op1[i] = n%10;
		n /= 10;
	}
	sort(op1, op1+4);
	memcpy(op2, op1, sizeof(int)*4);
	reverse(op2, op2+4);
	int p1 = get_num(op1), p2 = get_num(op2);
	int re = p2 - p1;
	printf("%04d - %04d = %04d\n", p2, p1, re);
	return re;
}

int main(int argc, char const *argv[]){
	int in;
	cin >> in;
	int tmp = rev(in);
	while(tmp != 0 && tmp != 6174)
		tmp = rev(tmp);
	return 0;
}