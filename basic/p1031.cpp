#include <iostream>
#include <string>

using namespace std;

bool isRight(string str, const int *q, const char *z){
	if(str.length() != 18) return false;
	int y = 0;
	for(unsigned int i = 0; i < str.length(); i++){
		if(i < 17){
			if((str.at(i)-'0') < 0 || (str.at(i)-'0') > 9)
				return false;
			y += (str.at(i)-'0')*q[i];
		}
		if(i == 17){
			y %= 11;
			if(z[y] == str.at(i))
				return true;
			else
				return false; 
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	const int q[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	const char z[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int N;
	cin >> N;
	bool allright = true;
	string *num = new string[N];
	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	for(int i = 0; i < N; i++){
		if(isRight(num[i], q, z) == false){
			allright = false;
			cout << num[i] << endl;
		}
	}
	if(allright)
		cout << "All passed" << endl;
	return 0;
}