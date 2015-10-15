#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 100000;

struct node{
	int mem, next;
	node():mem(0),next(-1){}
};

node all[MAXSIZE];

int main(int argc, char const *argv[])
{
	int f, n, k;
	cin >> f >> n >> k;
	int iter = n;
	while(iter--){
		int ad, mem, next;
		cin >> ad >> mem >> next;
		all[ad].mem = mem;
		all[ad].next = next;		
	}
	int size = 0;
	iter = f;
	while(iter != -1){
		size++;
		iter = all[iter].next;
	}
	int r = size/k;
	int rr = r;
	int last;
	while(rr--){
		vector<int> stack;
		iter = k;
		while(iter-- && f != -1){
			stack.push_back(f);
			f = all[f].next;
		}
		if(rr+1 != r)
			printf("%05d %d %05d\n", last, all[last].mem, stack.back());
		while(!stack.empty()){
			int top = stack.back();
			stack.pop_back();
			if(!stack.empty())
				printf("%05d %d %05d\n", top, all[top].mem, stack.back());
			last = top;
		}
	}
	if(f != -1)
		printf("%05d %d %05d\n", last, all[last].mem, f);
	else
		printf("%05d %d -1\n", last, all[last].mem);
	while(f != -1){
		if(all[f].next != -1)
			printf("%05d %d %05d\n", f, all[f].mem, all[f].next);
		else
			printf("%05d %d -1\n", f, all[f].mem);
		f = all[f].next;
	}
	return 0;
}