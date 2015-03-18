#include <iostream>
#include <math.h>

using namespace std;

class num{
public:
	int mem;
	num *next;
	num(){
		mem = -1;
		next = NULL;
	}
};

class sushu{
	num *head;
	num *tail;
	int size;
public:
	sushu(){
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void addone(num *add){
		if(head == NULL)
			head = tail = add;
		else{
			tail->next = add;
			tail = add;
		}
		size++;
	}

	bool isExisted(int n){
		num *ptr = head;
		while(ptr != NULL){
			if(ptr->mem == n)
				return true;
			ptr = ptr->next;
		}
		return false;
	}

	bool isSu_add(int n){
		num *ptr = head;
		while(ptr != NULL && ptr->mem < (sqrt(n)+1)){
			if(n%ptr->mem == 0)
				return false;
			ptr = ptr->next;
		}
		num *p = new num();
		p->mem = n;
		addone(p);
		return true;
	}

	void addmore(int n){
		if(size >= n) return;
		addmore(n-1);
		int i = tail->mem+1;
		while(!isSu_add(i))
			i++;
	}

	void print_info(int m, int n){
		int cnt = 1;
		int cnt1 = 1;
		num *ptr = head;
		while(ptr != NULL && cnt <= n){
			if(cnt >= m){
				if(cnt1%10 == 1)
					cout << ptr->mem;
				else
					cout << " " << ptr->mem;
				if(cnt1%10 == 0)
					cout << endl;
				cnt1++;
			}
			cnt++;
			ptr = ptr->next;
		}
	}
};

int main(){
	int M, N, cnt;
	cin >> M >> N;
	cnt = 1;
	sushu all;
	num *p;
	p = new num();
	p->mem = 2;
	all.addone(p);
	for(int i = 3; i <= 10000; i++){
		all.isSu_add(i);
	}
	all.addmore(N);
	all.print_info(M, N);
	return 0;
}