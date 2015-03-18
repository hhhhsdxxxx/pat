#include <iostream>
#include <string>

using namespace std;

int id(char c){
	if(c >= '0' && c <= '9')
		return c-'0';
	else if(c >= 'A' && c <= 'Z')
		return 36+c-'A';
	else if(c >= 'a' && c <= 'z')
		return 10+c-'a';
}

int main(int argc, char const *argv[])
{
	int num[62] = {0};
	string ball, want;
	cin >> ball >> want;
	for(int i = 0; i < ball.length(); i++){
		char ch = ball.at(i);
		num[id(ch)]++;
	}
	for(int i = 0; i < want.length(); i++){
		char ch = want.at(i);
		num[id(ch)]--;
	}
	int miss = 0;
	int more = 0;
	for(int i = 0; i < 62; i++){
		if(num[i] > 0)
			more += num[i];
		else if(num[i] < 0)
			miss += num[i];
	}
	if(miss >= 0)
		cout << "Yes " << more;
	else
		cout << "No " << -miss;
	return 0;
}