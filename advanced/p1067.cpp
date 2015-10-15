/*****swap sort******/
#include <iostream>
#include <map>

using namespace std;

int swap_sort(map<int, int> &num, int s){
	int cnt = 0;
	while(!num.empty()){
		if(s == 0){
			int k = num.begin()->first;
			s = num.begin()->second;
			num.erase(num.begin());
			num.insert(pair<int, int>(k, 0));
			cnt++;
		}
		map<int, int>::iterator it = num.find(s);
		s = it->second;
		// cout << s << endl;
		cnt++;
		num.erase(it);
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int N, s;
	map<int, int> num;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int k;
		cin >> k;
		if(k == 0)
			s = i;
		if(k != i && k != 0)
			num.insert(pair<int, int>(k, i));
	}
	cout << swap_sort(num, s);
	return 0;
}