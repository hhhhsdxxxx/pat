#include <iostream>
// #include <vector>
// #include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int num[10];
	for(int i = 0; i < 10; i++){
		cin >> num[i];
	}
	for(int i = 1; i < 10; i++)
		if(num[i] != 0){
			cout << i;
			num[i]--;
			break;
		}
	for(int i = 0; i < 10; i++){
		if(num[i] != 0){
			for(int j = num[i]; j > 0; j--)
				cout << i;
		}
	}
	return 0;
}