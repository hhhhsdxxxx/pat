#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
	int m, l, r;
	node():m(0),l(-1),r(-1){}
};

int cint = 0;

void reserve(vector<node> &tree, int root){
	if(root == -1)
		return;
	reserve(tree, tree[root].l);
	reserve(tree, tree[root].r);
	swap(tree[root].l, tree[root].r);
}

void in_travel(vector<node> &tree, int root){
	if(root == -1)
		return;
	in_travel(tree, tree[root].l);
	if(cint)
		cout << " ";
	else
		cint = 1;
	cout << tree[root].m;
	in_travel(tree, tree[root].r);
}

int main(){
	int N;
	cin >> N;
	vector<node> tree(N, node());
	vector<int> f(N, -1);
	for(int i = 0; i < N; ++i){
		tree[i].m = i;
		char a, b;
		int l, r;
		cin >> a >> b;
		l = (a=='-')?-1:a-'0';
		r = (b=='-')?-1:b-'0';
		tree[i].l = l;
		tree[i].r = r;
		if(l != -1)
			f[l] = i;
		if(r != -1)
			f[r] = i;
	}
	int root = 0;
	while(f[root] != -1)
		root = f[root];
	reserve(tree, root);
	queue<int> que;
	que.push(root);
	while(!que.empty()){
		int front = que.front();
		que.pop();
		if(front == -1)
			continue;
		if(cint)
			cout << " ";
		else
			cint = 1;
		cout << front;
		que.push(tree[front].l);
		que.push(tree[front].r);
	}
	puts("");
	cint = 0;
	in_travel(tree, root);
	return 0;
}