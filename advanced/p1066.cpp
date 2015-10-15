#include <iostream>
#include <cmath>

using namespace std;

int max(int a, int b){
	return a>b?a:b;
}

struct node{
	int m, h;
	node *l, *r;
	node():m(0),h(0),l(NULL),r(NULL){}
	node(int num):m(num),h(0),l(NULL),r(NULL){}
	const int height() const { return h; }
	void print_node(){
		cout << m << endl;
		if(l != NULL)
			l->print_node();
		if(r != NULL)
			r->print_node();
	}
	node* update(){
		int a, b;
		node *re = this;
		a = (l==NULL)?0:l->h+1;
		b = (r==NULL)?0:r->h+1;
		if(abs(a-b)>1){
			if(a > b){
				if(l->r == NULL || (l->l != NULL && l->l->height() > l->r->height())){
					re = l;
					l = re->r;
					re->r = this;
				}
				else {
					re = l->r;
					l->r = re->l;
					re->l = l;
					l = re->r;
					re->r = this;					
				}
			}
			else {
				if(r->l == NULL || (r->r != NULL && r->r->height() > r->l->height())){
					re = r;
					r = re->l;
					re->l = this;
				}
				else {
					re = r->l;
					r->l = re->r;
					re->r = r;
					r = re->l;
					re->l = this;
				}
			}
		}
		if(re == this)
			h = max(a, b);
		else {
			re->l->update();
			re->r->update();
			re->update();
		}
		return re;
	}
	node* add(node *p){
		if(p->m < m){
			if(l == NULL)
				l = p;
			else
				l = l->add(p);
		}
		else {
			if(r == NULL)
				r = p;
			else
				r = r->add(p);
		}
		return update();
	}
};

class avl_tree{
	int m_size;
	node *m_root;
public:
	avl_tree():m_root(NULL){}
	const int size() const { return m_size; }
	const int root() const { return (m_root==NULL)?0:m_root->m; }
	void insert(int in){
		node *ptr = new node(in);
		if(m_root){
			m_root = m_root->add(ptr);
			// cout << "c\n";
		}
		else
			m_root = ptr;
	}

	void print_all(){
		m_root->print_node();
	}

};

int main(int argc, char const *argv[])
{
	/* code */
	int N, num;
	avl_tree t;
	cin >> N;
	while(N--){
		cin >> num;
		t.insert(num);
		// t.print_all();
		// cout << "------\n";
	}
	cout << t.root();
	return 0;
}