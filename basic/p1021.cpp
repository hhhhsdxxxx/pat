#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	int d[10];
	for(int i = 0; i < 10; i++)
		d[i] = 0;
	for(int i = 0; i < num.length(); i++)
		d[num.at(i)-'0']++;
	for(int i = 0; i < 10; i++)
		if(d[i] != 0)
			cout << i << ":" << d[i] << endl;
	return 0;
}