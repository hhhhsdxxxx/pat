#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long long_64;

struct stu{
	long_64 id;
	int seat;
	stu():id(0),seat(0){}
}; 

int main(){
	int N;
	cin >> N;
	vector<stu> table(N, stu());
	for(int i = 0; i < N; ++i){
		long_64 id;
		int seat1, seat2;
		cin >> id >> seat1 >> seat2;
		table[seat1-1].id = id;
		table[seat1-1].seat = seat2;
	}
	cin >> N;
	while(N--){
		int k;
		cin >> k;
		printf("%014lld %d\n", table[k-1].id, table[k-1].seat);
	}
	return 0;
}