#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int root(int begin, int n){
	if(n <= 0)
		return -1;
	if(n == 1)
		return begin;
	int re = 0, tmp = 1;
	n -= tmp;
	while(n){
		tmp = tmp << 1;
		if(tmp > n){
			if(n > (tmp >> 1))
				re += (tmp >> 1);
			else
				re += n;
			n = 0;
			break;
		}
		re += (tmp >> 1);
		n -= tmp;
	}
	return begin+re;
}

struct my_pair{
	int begin, cnt;
	my_pair(int _begin, int _cnt):begin(_begin),cnt(_cnt){}
};

int main(){
	int n;
	cin >> n;
	vector<int> node;
	while(n--){
		int num;
		cin >> num;
		node.push_back(num);
	}
	sort(node.begin(), node.end());
	queue<my_pair> que;
	vector<int> ans;
	que.push(my_pair(0, node.size()));
	while(!que.empty()){
		my_pair it = que.front();
		int r = root(it.begin, it.cnt);
		ans.push_back(node[r]);
		if(r > it.begin)
			que.push(my_pair(it.begin, r-it.begin));
		if(r < it.begin+it.cnt-1)
			que.push(my_pair(r+1, it.cnt-(r-it.begin)-1));
		que.pop();
	}
	for(int i = 0; i < ans.size(); ++i){
		if(i)
			cout << " ";
		cout << ans[i];
	}

	return 0;
}