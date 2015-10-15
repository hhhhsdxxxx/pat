#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct m_pair{
	int id, deep;
	m_pair():id(0),deep(0){}
	m_pair(int _id, int d):id(_id),deep(d){}
};

vector<vector<int>> *map;
bool *v;
int n, l;

void push(int p, queue<m_pair> &que, int deep, int *cnt){
	for(int i = 0; i < (*map)[p].size(); ++i){
		int k = (*map)[p][i];
		if(!v[k]){
			que.push(m_pair(k, deep));
			v[k] = true;
			(*cnt)++;
		}
	}
}

int cal(int i){
	queue<m_pair> que;
	v = new bool[n];
	memset(v, false, n*sizeof(bool));
	v[i] = true;
	que.push(m_pair(i, 0));
	int cnt = 0;
	while(!que.empty()){
		m_pair it = que.front();
		if(it.deep < l){
			// cout << it.id << endl;
			push(it.id, que, it.deep+1, &cnt);
		}
		que.pop();
	}
	delete[] v;
	return cnt;
}

int main(int argc, char const *argv[]){
	cin >> n >> l;
	map = new vector<vector<int>>(n, vector<int>());
	// v = new bool[n];
	// memset(v, false, n*sizeof(bool));
	for(int i = 0; i < n; ++i){
		int k, m;
		cin >> k;
		while(k--){
			cin >> m;
			(*map)[m-1].push_back(i);
		}
	}
	int c;
	cin >> c;
	while(c--){
		int r;
		cin >> r;
		cout << cal(r-1) << endl;
	}	
	return 0;
}