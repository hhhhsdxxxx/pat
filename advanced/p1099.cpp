#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int l, r, d, data, i;
	node():l(-1),r(-1),d(0),data(0),i(0){}
};

bool cmp0(node a, node b){
	return a.i < b.i;
}

bool cmp1(node a, node b){
	return (a.d == b.d)?(a.data<b.data):(a.d<b.d);
}

void search(node *tree, int me, int deep, int &cnt){
	tree[me].d = deep+1;
	if(tree[me].l != -1)
		search(tree, tree[me].l, tree[me].d, cnt);
	tree[me].i = cnt;
	cnt++; 
	if(tree[me].r != -1)
		search(tree, tree[me].r, tree[me].d, cnt);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	node *tree = new node[N];
	int *num = new int[N];
	for(int i = 0; i < N; i++)
		cin >> tree[i].l >> tree[i].r;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num+N);
	int cnt = 0;
	search(tree, 0, 0, cnt);
	sort(tree, tree+N, cmp0);
	for(int i = 0; i < N; i++)
		tree[i].data = num[i];
	sort(tree, tree+N, cmp1);
	for(int i = 0; i < N; i++){
		if(i != 0)
			cout << " ";
		cout << tree[i].data;
	}
	return 0;
}