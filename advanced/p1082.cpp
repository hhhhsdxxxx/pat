#include <iostream>

using namespace std;

char word[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char dan[5][5] = {"Yi", "Wan", "Qian", "Bai", "Shi"};

void ch_in_ch(int num){
	if(num == 0)
		return;
	int q = num/1000;
	if(q != 0)
		cout << word[q] << " " << dan[2];
	int b = num/100%10;
	if(b != 0){
		if(q != 0)
			cout << " ";
		cout << word[b] << " " << dan[3];
	}
	int s = num/10%10;
	if(s != 0){
		if(q != 0 && b == 0)
			cout << " " << word[0] << " ";
		if(b != 0)
			cout << " ";
		cout << word[s] << " " << dan[4];
	}
	int g = num%10;
	if(g != 0){
		if(num > 10 && s == 0)
			cout << " " << word[0] << " ";
		if(num > 10 && s != 0)
			cout << " ";
		cout << word[g];
	}
}

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	if(num < 0){
		cout << "Fu ";
		num = -num;
	}
	int yi = num/100000000, wan = num/10000%10000, ge = num%10000;
	if(yi != 0){
		ch_in_ch(yi);
		cout << " " << dan[0];
		if(wan < 1000 && wan != 0)
			cout << " " << word[0];
		if(wan != 0)
			cout << " ";
		ch_in_ch(wan);
		if(wan != 0)
			cout << " " << dan[1]; 
		if(ge < 1000 && ge != 0)
			cout << " " << word[0];
		if(ge != 0)
			cout << " ";
		ch_in_ch(ge);
	}
	else{
		ch_in_ch(wan);
		if(wan != 0)
			cout << " " << dan[1];
		if(ge < 1000 && ge != 0 && wan != 0)
			cout << " " << word[0];
		if(wan != 0 && ge != 0)
			cout << " ";
		ch_in_ch(ge);	
	}
	if(num == 0)
		cout << word[0];
	return 0;
}