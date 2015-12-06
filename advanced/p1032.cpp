#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;

struct node{
	char l;
	int next, cnt;
	node():l(0),next(-1),cnt(0){}
	bool more(){ return cnt >= 2; }
};

vector<node> address(MAXN, node());

int main(){
	int w1, w2, n;
	cin >> w1 >> w2 >> n;
	while(n--){
		int addr, next;
		char l;
		cin >> addr >> l >> next;
		address[addr].l = l;
		address[addr].next = next;
	}
	// int cp = w1;
	while(w1 != -1){
		address[w1].cnt++;
		w1 = address[w1].next;
	}
	while(w2 != -1){
		if(address[w2].cnt)
			break;
		w2 = address[w2].next;
	}
	// while(cp != -1){
	// 	if(address[cp].more())
	// 		break;
	// 	cp = address[cp].next;
	// }
	if(w2 != -1)
		printf("%05d\n", w2);
	else
		puts("-1");
	return 0;
}