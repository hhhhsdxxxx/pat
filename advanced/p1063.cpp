#include <iostream>
#include <set>

using namespace std;

set<int> *que;

double cal(int i, int j){
	double sam = 0.0;
	int ptr = 0, size1 = que[i].size(), size2 = que[j].size();
	set<int>::iterator q1 = que[i].begin(), q2 = que[j].begin();
	while(q1 != que[i].end() && q2 != que[j].end()){
		if(*q1 == *q2){
			sam += 1.0;
			++q1;
			++q2;
			--size1;
			--size2;
		}
		else if(*q1 < *q2){
			++q1;
			--size1;
		}
		else {
			++q2;
			--size2;
		}
		++ptr;
	}
	ptr += size1+size2;
	return sam/ptr*100.0;
}

int main(){
	int n;
	cin >> n;
	que = new set<int>[n];
	for(int i = 0; i < n; ++i){
		int size;
		cin >> size;
		while(size--){
			int num;
			cin >> num;
			que[i].insert(num);
		}
	}
	int k;
	cin >> k;
	while(k--){
		int i, j;
		cin >> i >> j;
		printf("%.1lf%%\n", cal(i-1, j-1));
	}
	return 0;
}