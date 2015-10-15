#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXINT = 10010;

vector<int> times(MAXINT, 0);
vector<int> cnt(MAXINT, 0);

int main(){
	set<int> s;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int d;
		scanf("%d", &d);
		++cnt[d];
		if(!times[d]) {
			times[d] = i+1;
			s.insert(d);
		}
		else {
			if(cnt[d] == 2){
				s.erase(d);
			}
		}
	}
	int r, m;
	if(s.empty())
		puts("None");
	else {
		m = times[*(s.begin())];
		r = *(s.begin());
		for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
			if(times[*it] < m){
				m = times[*it];
				r = *it;
			}
		}
		// cout << times[888];
		printf("%d", r);
	}

	return 0;
}