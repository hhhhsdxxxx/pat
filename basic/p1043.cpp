#include <iostream>
#include <string>

using namespace std;

int main(){
	int cnt[6] = {0};
	string in;
	cin >> in;
	for(unsigned int i = 0; i < in.length(); ++i){
		switch(in[i]){
			case 'P':
			++cnt[0];
			break;
			case 'A':
			++cnt[1];
			break;
			case 'T':
			++cnt[2];
			break;
			case 'e':
			++cnt[3];
			break;
			case 's':
			++cnt[4];
			break;
			case 't':
			++cnt[5];
			break;
			default:
			break;
		}
	}
	int blank = 0;
	while(blank != 6){
		blank = 0;
		for(int i = 0; i < 6; ++i){
			if(cnt[i]){
				if(i == 0)
					cout << 'P';
				else if(i == 1)
					cout << 'A';
				else if(i == 2)
					cout << 'T';
				else if(i == 3)
					cout << 'e';
				else if(i == 4)
					cout << 's';
				else if(i == 5)
					cout << 't';
				--cnt[i];
			}
			else
				++blank;
		}
	}
	return 0;
}