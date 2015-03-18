#include <iostream>

using namespace std;

int main(){
	int a, ex, i;
	i = 0;
	while((cin >> a >> ex) != NULL){
		if(i == 0 && ex == 0)
			cout << "0 0";
		if(ex >= 1)
			if(i == 0)
				cout << ex*a << " " << ex-1;
			else
				cout << " " << ex*a << " " << ex-1;
		i++;
	}
	return 0;
}