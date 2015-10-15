#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> q;

typedef vector<int>::iterator p_int;

bool same(p_int cb1, p_int cb2, p_int ce1){
	while(cb1 != ce1){
		if(*cb1 != *cb2)
			return 0;
		++cb1;
		++cb2;
	}
	return 1;
}

bool isort(p_int begin, p_int end){
	bool r = 0;
	p_int ptr = begin+1;
	for(; ptr < end; ++ptr){
		p_int p = ptr-1;
		int key = *ptr;
		while(p >= begin && key < *p){
			*(p+1) = *p;
			--p;
		}
		*(p+1) = key;
		if(same(begin, q.begin(), end))
			r = 1;
		else if(r && !same(begin, q.begin(), end))
			return 1;
	}
	return 0;
}

bool hsort(p_int begin, p_int end){
	bool r = 0;
	make_heap(begin, end);
	p_int ptr = end;
	while(begin != ptr){
		pop_heap(begin, ptr);
		ptr--;
		if(same(begin, q.begin(), end))
			r = 1;
		else if(r && !same(begin, q.begin(), end))
			return 1;
	}
	return 0;
}

int main(){
	int n;
	cin >> n;
	vector<int> is(n, 0), hs(n, 0);
	for(int i = 0; i < n; ++i){
		int d;
		cin >> d;
		is[i] = hs[i] = d;
	}
	for(int i = 0; i < n; ++i){
		int d;
		cin >> d;
		q.push_back(d);
	}
	if(isort(is.begin(), is.end())){
		puts("Insertion Sort");
		for(int i = 0; i < n; ++i){
			if(i)
				cout << " ";
			cout << is[i];
		}
	}
	else if(hsort(hs.begin(), hs.end())){
		puts("Heap Sort");
		for(int i = 0; i < n; ++i){
			if(i)
				cout << " ";
			cout << hs[i];
		}
	}
	return 0;
}