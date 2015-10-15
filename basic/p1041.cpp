#include <iostream>

using namespace std;

int main(){
	char word[10];
	int p = 10, cntl(0), cntb(0), cntd(0), cnto(0);
	while(p--)
		word[p] = getchar();
	for(int i = 0; i < 10; ++i){
		if(word[i] >= 'A' && word[i] <= 'Z' || word[i] >= 'a' && word[i] <= 'z')
			++cntl;
		else if(word[i] >= '0' && word[i] <= '9')
			++cntd;
		else if(word[i] == ' ' || word[i] == '\n')
			++cntb;
		else
			++cnto;
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d", cntl, cntb, cntd, cnto);
	return 0;
}