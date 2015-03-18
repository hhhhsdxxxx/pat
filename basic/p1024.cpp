#include <iostream>
#include <string>

using namespace std;

int s_to_int(string str){
	int re = 0;
	for(int i = 0; i < str.length(); i++)
		re = re*10 + str.at(i)-'0';
	return re;
}

int main(int argc, char const *argv[])
{
	string n;
	cin >> n;
	char sign = (n.at(0) == '+') ? '+' : '-';
	int l = n.find('E');
	string num = n.substr(1, l-1);
	int sign2 = (n.at(l+1) == '+') ? 1 : -1;
	string ex = n.substr(l+2, n.length()-l-2);
	int e = s_to_int(ex);
	l = num.find('.');
	// cout << num << endl;
	if(sign2 == -1)
		l -= e;
	else
		l += e;
	// cout << l << endl;
	int i;
	cout << ((sign == '-') ? "-" : "");
	int length = int(num.length());
	if(l > 0){
		for(i = 0; i <= l; i++){
			if(i < length){
				if(num.at(i) != '.')
					cout << num.at(i);
			}
			else
				cout << "0";
		}
		if(i == (l+1) && l < (length-1)){
			cout << ".";
			for(; i < length; i++)
				cout << num.at(i);
		}
	}
	else{
		cout << "0.";
		for(i = l; i < length; i++){
			if(i < 0)
				cout << "0";
			else{
				if(num.at(i) != '.')
					cout << num.at(i); 
			}
		}
	}
	return 0;
}