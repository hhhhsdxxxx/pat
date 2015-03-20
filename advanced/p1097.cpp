#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int *ad = new int[100000];
	int *data = new int[100000];
	set<int> s;
	int head, N, fdx;
	cin >> head >> N;
	for(int i = 0; i < N; i++){
		int ads, d, nds;
		scanf("%d %d %d", &ads, &d, &nds);
		ad[ads] = nds;
		data[ads] = d;
	}
	int ptr, rt, ft, ptr2;
	ptr = rt = head;
	fdx = -1;
	do{
		ptr2 = ad[ptr];
		ad[ptr] = -1;
		if(ptr != head){
			if(s.count(abs(data[ptr]))){
				if(fdx == -1){
					fdx = ptr;
				}
				else
					ad[ft] = ptr;
				ft = ptr;
			}
			else{
				ad[rt] = ptr;
				rt = ptr;
				s.insert(abs(data[ptr]));
			}
		}
		else{
			s.insert(abs(data[head]));
		}
		ptr = ptr2;
	}while(ptr != -1);
	for(ptr = head; ad[ptr] != -1; ptr = ad[ptr]){
		printf("%05d %d %05d\n", ptr, data[ptr], ad[ptr]);
	}
	printf("%05d %d -1\n", ptr, data[ptr], ad[ptr]);
	if(fdx != -1){
		for(ptr = fdx; ad[ptr] != -1; ptr = ad[ptr]){
			printf("%05d %d %05d\n", ptr, data[ptr], ad[ptr]);
		}
		printf("%05d %d -1\n", ptr, data[ptr], ad[ptr]);
	}
	return 0;
}