#include <iostream>
#include <string>

using namespace std;

int p = 0;

int get_num(string &str){
	int re = 0;
	for(; p < str.length() && str.at(p) <= '9' && str.at(p) >= '0'; p++)
		re = re*10+str[p]-'0';
	return re;
}

int main(int argc, char const *argv[])
{
	string in;
	cin >> in;
	p = in.find('E')+2;
	int sign_e = in.at(p-1)=='+'?1:-1;
	int expo = get_num(in);
	// cout << expo << endl;
	if(in.at(0) == '-')
		cout << "-";
	if(sign_e > 0 || expo == 0){
		cout << in.at(1);
		int ptr = 3;
		bool f = false;
		while(expo--){
			if(in.at(ptr) == 'E')
				f = true;
			else {
				cout << in.at(ptr);
				ptr++;
			}
			if(f)
				cout << "0";
		}
		// cout << ptr << endl;
		if(!f && in.at(ptr) != 'E')
			cout << ".";
		while(in.at(ptr++) != 'E')
			cout << in.at(ptr-1);
	}
	else {
		cout << "0.";
		while(--expo)
			cout << "0";
		int ptr = 1;
		while(in.at(ptr++) != 'E')
			if(in.at(ptr-1) != '.')
				cout << in.at(ptr-1);
	}
	return 0;
}