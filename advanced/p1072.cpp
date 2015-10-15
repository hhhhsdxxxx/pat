#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

struct dis{
	int id, dist;
	dis(int idd, int diss):id(idd),dist(diss){}
	bool operator<(const dis &c){
		return dist < c.dist;
	}
};

struct ans{
	int id, min, aver;
	ans(int mmin, int aaver, int iid):min(mmin),aver(aaver),id(iid){}
};

bool cmp(const ans &a, const ans &b){
	if(a.min != b.min)
		return a.min > b.min;
	else {
		if(a.aver != b.aver)
			return a.aver < b.aver;
		else
			return a.id < b.id;
	}	
}

vector<vector<dis>> *map;
vector<ans> r;

int find_min(set<int> &que, int *d){
	int min = -1, id = 0;
	set<int>::iterator er = que.begin();
	for(set<int>::iterator it = que.begin(); it != que.end(); ++it){
		if(min == -1){
			min = d[*it];
			continue;
		}
		if(d[*it] < min){
			min = d[*it];
			er = it;
		}
	}
	id = *er;
	que.erase(er);
	return id;
}

void find(int gid, int n, int m, int l){
	bool *city = new bool[n+m];
	bool isok = 1;
	int *d = new int[n+m];
	set<int> que;
	memset(d, -1, sizeof(int)*(n+m));
	memset(city, 0, sizeof(bool)*(n+m));
	d[gid] = 0;
	que.insert(gid);
	while(!que.empty()){
		int id = find_min(que, d);
		if(d[id] > l){
			isok = 0;
			break;
		}
		// cout << d[id] << endl;
		for(int i = 0; i < (*map)[id].size(); ++i){
			dis tmp = (*map)[id][i];
			if(!city[tmp.id]){
				if(d[tmp.id] == -1)
					d[tmp.id] = tmp.dist+d[id];
				else{
					if(d[tmp.id] > tmp.dist+d[id])
						d[tmp.id] = tmp.dist+d[id];
				}
				if(que.find(tmp.id) == que.end())
					que.insert(tmp.id);
			}
		}
		city[id] = 1;
	}
	if(isok){
		int min = d[0], aver = d[0];
		for(int i = 1; i < n; ++i){
			aver += d[i];
			if(min > d[i])
				min = d[i];
		}
		r.push_back(ans(min, aver, gid-n+1));
	}
	delete[] city;
	delete[] d;
}

int get_id(string s, int n){
	int re;
	stringstream ss;
	if(s[0] == 'G')
		ss << s.substr(1, s.length()-1);
	else
		ss << s;
	ss >> re;
	if(s[0] == 'G')
		re += n;
	return re-1;
}

int main(){
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	map = new vector<vector<dis>>(N+M, vector<dis>());
	while(K--){
		string c1, c2;
		int d;
		cin >> c1 >> c2 >> d;
		int city1 = get_id(c1, N), city2 = get_id(c2, N);
		// cout << city1 << " " << city2 << endl;
		(*map)[city1].push_back(dis(city2, d));
		(*map)[city2].push_back(dis(city1, d));
	}
	for(int i = N; i < M+N; ++i)
		find(i, N, M, D);
	if(r.empty())
		cout << "No Solution";
	else {
		sort(r.begin(), r.end(), cmp);
		printf("G%d\n%.1f %.1f", r.front().id, float(r.front().min), flaot(r.front().aver)/N);
	}
	return 0;
}