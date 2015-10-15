#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct stu{
	int id, ts, fp, *sc, size;
	bool isb;
	stu():id(0),ts(0),sc(NULL),size(0),fp(0),isb(false){}
	void add(int p, int s, int pts){
		if(p >= size)
			return;
		if(!sc){
			sc = new int[size];
			memset(sc, -1, size*sizeof(int));
		}
		if(s == -1 && sc[p] == -1)
			sc[p] = 0;
		else
			isb = true;
		if(sc[p] < s){
			ts += -sc[p]+s;
			if(sc[p] == -1)
				ts--;
			sc[p] = s;
			if(s == pts)
				fp++;
		}
	}
	void print_info(){
		if(!sc)
			return;
		printf("%05d %d", id, ts);
		for(int i = 0; i < size; ++i){
			if(sc[i] == -1)
				cout << " -";
			else
				cout << " " << sc[i];
		}
		cout << endl;
	}
	// bool operator<(stu p){
	// 	if(ts != p.ts)
	// 		return ts > p.ts;
	// 	else {
	// 		if(fp != p.fp)
	// 			return fp > p.fp;
	// 		else
	// 			return id < p.id;
	// 	}
	// }
	bool is_nosubmit(){
		return !isb;
	}
	bool operator!=(const stu &p){
		return ts != p.ts;
	}
};

bool cmp(stu a, stu b){
	if(a.ts != b.ts)
		return a.ts > b.ts;
	else {
		if(a.fp != b.fp)
			return a.fp > b.fp;
		else {
			if(a.isb != b.isb)
				return a.isb > b.isb;
			else
				return a.id < b.id;
		}
	}	
}

int main(int argc, char const *argv[]){
	int n, k, m, *sc;
	stu *st;
	cin >> n >> k >> m;
	st = new stu[n];
	for(int i = 0; i < n; ++i){
		st[i].size = k;
		st[i].id = i+1;
	}
	sc = new int[k];
	for(int i = 0; i < k; ++i)
		cin >> sc[i];
	while(m--){
		int id, pid, psc;
		cin >> id >> pid >> psc;
		if(sc[pid-1] < psc)
			continue;
		st[id-1].add(pid-1, psc, sc[pid-1]);
	}
	sort(st, st+n, cmp);
	int rank = 1;
	for(int i = 0; i < n; ++i){
		if(st[i].is_nosubmit())
			break;
		if(i == 0)
			cout << rank << " ";
		else {
			if(st[i] != st[i-1])
				rank = i+1;
			cout << rank << " ";
		}
		st[i].print_info();
	}
	return 0;
}