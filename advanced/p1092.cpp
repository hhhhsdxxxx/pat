#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string ball, want;
	cin >> ball >> want;

	int miss = 0;
	for(int i = 0; i < want.length(); i++){
		char ch = want.at(i);
		int k = ball.find(ch, 0);
		if(k == -1)
			miss++;
		else{
			ball.at(k) = '*';
		}
	}
	if(miss == 0)
		cout << "Yes " << ball.length()-want.length();
	else
		cout << "No " << miss;
	return 0;
}