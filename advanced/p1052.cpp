#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

struct node{
	int addr, key;
	node():addr(0),key(0){}
	node(int addrr, int keyy):addr(addrr),key(keyy){}
};

bool cmp(const node &a, const node &b){
	if(a.key != b.key)
		return a.key < b.key;
	else
		return a.addr < b.addr;
}

int main(){
	int n, head;
	cin >> n >> head;
	vector<int> data(100000, 0);
	vector<int> next(100000, -1);
	for(int i = 0; i < n; ++i){
		int addr, key, nex;
		cin >> addr >> key >> nex;
		data[addr] = key;
		next[addr] = nex;
	}
	vector<node> list;
	while(head != -1){
		// cout << head << endl;
		list.push_back(node(head, data[head]));
		head = next[head];
	}
	sort(list.begin(), list.end(), cmp);
	if(!list.empty())
		printf("%d %05d\n", list.size(), list[0].addr);
	else
		puts("0 -1");
	for(int i = 0; i < list.size(); ++i){
		printf("%05d %d ", list[i].addr, list[i].key);
		if(i == list.size()-1)
			puts("-1");
		else
			printf("%05d\n", list[i+1].addr);
	}
	return 0;
}