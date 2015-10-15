#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct person{
	int w, cnt;
	person():w(0),cnt(0){}
	person(int ww):w(ww),cnt(0){}
	person& operator+=(int _cnt){
		cnt+=_cnt;
		return *this;
	}
	bool operator>(const person &a){
		return w>a.w;
	}
};

ostream& operator<<(ostream &ou, person &a){
	ou << a.cnt;
	return ou;
}

int main(){
	int n(0), m(0), gcnt(0);
	cin >> n >> m;
	queue<int> game;
	vector<person> player(n, person());
	for(int i = 0; i < n; ++i)
		cin >> player[i].w;
	int N = n;
	while(n--){
		int order;
		cin >> order;
		game.push(order);
	}
	while(game.size()>1){
		int fail_rank = game.size()/m+(game.size()%m?1:0);
		// cout << fail_rank << endl;
		queue<int> re;
		while(!game.empty()){
			int p = m, max = game.front();
			while(p-- && !game.empty()){
				if(max == game.front()){
					game.pop();
					continue;
				}
				if(player[game.front()]>player[max]){
					player[max]+=fail_rank+1;
					max = game.front();
				}
				else
					player[game.front()]+=fail_rank+1;
				game.pop();
			}
			re.push(max);
		}
		game = re;
		// for(int i = 0; i < N; ++i){
		// 	if(i)
		// 		cout << " ";
		// 	cout << player[i];
		// }
		// cout << "\n";
	}
	player[game.front()]+=1;
	for(int i = 0; i < N; ++i){
		if(i)
			cout << " ";
		cout << player[i];
	}

	return 0;
}