#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct gstu{
	int id, GE, GI, *k;

	gstu():id(0),GE(0),GI(0),k(NULL){}

	bool operator==(gstu &c){
		return (GE+GI)/2 == (c.GE+c.GI)/2 && GE == c.GE;
	}

	bool operator!=(gstu &c){
		return !((*this)==c);
	}
};

// struct node{
// 	int id;
// 	node *next;
// 	node(int k):id(k),next(NULL){}
// };

// struct list{
// 	node *root, *tail;

// 	list():root(NULL),tail(NULL){}

// 	void add(gstu *stu, int id){
// 		node *ptr = new node(id);
// 		if(root == NULL){
// 			root = ptr;
// 			tail = ptr;
// 		}
// 		else {
// 			if(stu[id].id > stu[tail->id].id){
// 				tail->next = ptr;
// 				tail = ptr;
// 			}
// 			else if(stu[id].id < stu[root->id].id){
// 				ptr->next = root;
// 				root = ptr;
// 			}
// 			else {
// 				node *p;
// 				for(p = root; stu[p->next->id].id < stu[id].id; p = p->next);
// 				ptr->next = p->next;
// 				p->next = ptr;
// 			}
// 		}
// 	}

// 	void print_all(gstu *stu){
// 		node *ptr;
// 		for(ptr = root; root != NULL; ptr = ptr->next){
// 			if(ptr != root)
// 				cout << " ";
// 			cout << stu[ptr->id].id;
// 			if(ptr == tail)
// 				break;
// 		}
// 		cout << endl;
// 	}
// };

struct gsch{
	int qua, last, now;
	vector<int> id, true_id;
	gsch():qua(0),id(NULL),last(0),now(0){}

	bool admit(gstu *stu, int _id){
		if(now >= qua && stu[last] != stu[_id])
			return false;
		id.push_back(_id);
		true_id.push_back(stu[_id].id);
		now++;
		last = _id;
		return true;
	}

	void print_all(){
		if(!true_id.empty()){
			std::sort(true_id.begin(), true_id.end());
			for(unsigned int i = 0; i < true_id.size(); ++i){
				if(i != 0)
					cout << " ";
				cout << true_id.at(i);
			}
		}
		cout << endl;
	}
};

bool cmp(gstu a, gstu b){
	if((a.GE+a.GI)/2 != (b.GE+b.GI)/2)
		return (a.GE+a.GI)/2 > (b.GE+b.GI)/2;
	else{
		if(a.GE != b.GE)
			return a.GE > b.GE;
		else
			return *(a.k) < *(b.k);
	}
}

void admit(gstu *stu, gsch *sch, int n, int k){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			if(sch[stu[i].k[j]].admit(stu, i))
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, M, K;
	gstu *stu;
	gsch *sch;
	cin >> N >> M >> K;
	stu = new gstu[N];
	for(int i = 0; i < N; ++i)
		stu[i].k = new int[K];
	sch = new gsch[M];
	for(int i = 0; i < M; i++)
		cin >> sch[i].qua;
	for(int i = 0; i < N; i++){
		stu[i].id = i;
		cin >> stu[i].GE >> stu[i].GI;
		for(int j = 0; j < K; ++j)
			cin >> stu[i].k[j];
	}
	sort(stu, stu+N, cmp);
	// for(int i = 0; i < N; i++)
	// 	cout << stu[i].id;
	admit(stu, sch, N, K);
	for(int i = 0; i < M; ++i)
		sch[i].print_all();
	return 0;
}