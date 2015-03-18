#include <iostream>

using namespace std;

void print_info(int w, char *num){
	char ch;
	switch(w){
		case 3:
		for(ch = '0'; ch < num[w-3]; ch++)
			cout << "B";
		case 2:
		for(ch = '0'; ch < num[w-2]; ch++)
			cout << "S";
		case 1:
		for(ch = '1'; ch <= num[w-1]; ch++)
			cout << ch;
		case 0:
		break;
		default:
		break;
	}
}

int main(){
	char num[4];
	cin >> num;
  	int w = 0;
  	for(; num[w] != 0; w++);
  	print_info(w, num);
	return 0;
}