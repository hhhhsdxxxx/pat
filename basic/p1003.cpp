#include <iostream>

using namespace std;

void print_info(char *str){
	int beforeA = 0;
	int afterA  = 0;
	int centerA = 0;
	bool getP = false;
	bool getA = false;
	bool getT = false;
	for(int i = 0; str[i] != 0; i++){
		if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T'){
			cout << "NO" << endl;
			return;
		}
		if(str[i] == 'P'){
			if(!getP)
				getP = true;
			else{
				getP = false;
				break;
			}
		}
		else if(str[i] == 'A'){
			if(getP){
				if(!getT){
					if(!getA)
						getA = true;
					centerA++;
				}
				else{
					afterA++;
				}
			}
			else{
				beforeA++;
			}
		}
		else if(str[i] == 'T'){
			if(getA){
				if(!getT)
					getT = true;
				else{
					getT = false;
					break;
				}
			}
			else
				break;
		}
	}

	if(getP && getA && getT){
		if(afterA != 0 && beforeA != 0){
			if(centerA == afterA/beforeA && afterA % beforeA == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(afterA == 0 && beforeA == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
}

int main(){
	int n;
	cin >> n;

	char str[101];
	while(n--){
		cin >> str;
		print_info(str);
	}
	return 0;
}