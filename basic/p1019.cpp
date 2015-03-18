#include <iostream>
#include <algorithm>

using namespace std;

bool cmp1(char a, char b){
	return a>b;
}

bool cmp2(char a, char b){
	return a<b;
}

int num(char *n){
	int tmp = 0;
	for(int i = 0; n[i] != 0; i++)
		tmp = tmp*10 + n[i]-'0';
	return tmp;
}

void num_to_char(int n, char *num){
	num[0] = n/1000 + '0';
	num[1] = n/100%10 + '0';
	num[2] = n/10%10 + '0';
	num[3] = n%10 + '0';
}

int main(int argc, char const *argv[])
{
	char n[5];
	cin >> n;
	n[4] = 0;
    int num1 = num(n);
    num_to_char(num1, n);
    int num2 = 0;
	sort(n, n+4, cmp1);
	num1 = num(n);
	sort(n, n+4, cmp2);
	num2 = num(n);
	if(num1 == num(n))
		cout << n << " - " << n << " = " << "0000";
	else{
		cout << num1 << " - " << n << " = ";
		num_to_char(num1-num2, n);
		cout << n << endl;
		while((num1-num2) != 6174){
			sort(n, n+4, cmp1);
			num1 = num(n);
			sort(n, n+4, cmp2);
			num2 = num(n);
			cout << num1 << " - " << n << " = ";
			num_to_char(num1-num2, n); 
			cout << n << endl;
		}
	}
	return 0;
}