#include <iostream>
#include <string>

using namespace std;

bool first = true;

struct tree_node{
	int mem;
	tree_node *l, *r, *f;

	tree_node(int i):mem(i),l(NULL),r(NULL),f(NULL){}
};

void post_travel(tree_node *root){
	if(root == NULL)
		return;
	post_travel(root->l);
	post_travel(root->r);
	if(!first)
		cout << " ";
	else
		first = false;
	cout << root->mem;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	tree_node *root, *tail, *ptr;
	root = tail = NULL;
	bool isleft = true;
	for(int i = 0; i < 2*N; ++i){
		string op;
		cin >> op;
		if(op == "Push"){
			int num;
			cin >> num;
			ptr = new tree_node(num);
			if(root == NULL)
				root = ptr;
			else{
				if(isleft)
					tail->l = ptr;
				else
					tail->r = ptr;
				ptr->f = tail;
			}
			tail = ptr;
			isleft = true;
		}
		else if(op == "Pop"){
			if(isleft)
				isleft = false;
			else{
				tail = tail->f;
				while(tail->r)
					tail = tail->f;
			}
		}
	}
	post_travel(root);
	return 0;
}