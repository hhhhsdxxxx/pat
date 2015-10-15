#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> card(54, string());

void initial(){
	int k = 4;
	card[52] = "J1";
	card[53] = "J2";
	for(int i = 1; i <= 13; ++i){
		stringstream ss;
		ss << i;
		string tmp;
		ss >> tmp;
		// cout << tmp << endl;
		card[i-1] = "S"+tmp;
		card[i+12] = "H"+tmp;
		card[i+25] = "C"+tmp;
		card[i+38] = "D"+tmp;
	}
}

int main(){
	vector<int> ori(54, 0), aft(54, 0), change(54, 0);
	initial();
	for(int i = 1; i < 54; ++i)
		aft[i] = i;
	int r;
	cin >> r;
	for(int i = 0; i < 54; ++i)
		cin >> change[i];
	while(r--){
		copy(aft.begin(), aft.end(), ori.begin());
		for(int i = 0; i < 54; ++i){
			aft[change[i]-1] = ori[i];
		}
	}
	for(int i = 0; i < 54; ++i){
		if(i)
			cout << " ";
		cout << card[aft[i]];
	}
	return 0;
}