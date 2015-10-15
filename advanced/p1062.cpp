#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct person{
	int id, vs, ts;
	person(int _id, int _vs, int _ts):id(_id),vs(_vs),ts(_ts){}
};

ostream& operator<<(ostream &ou, person &a){
	printf("%08d %d %d\n", a.id, a.vs, a.ts);
	return ou;
}

bool cmp(const person &a, const person &b){
	if(a.ts+a.vs != b.ts+b.vs)
		return a.ts+a.vs > b.ts+b.vs;
	else{
		if(a.vs != b.vs)
			return a.vs > b.vs;
		else
			return a.id < b.id;
	}
}

int main(){
	int n, l, h;
	cin >> n >> l >> h;
	vector<person> sage, noble, fool, small;
	while(n--){
		int id, vs, ts;
		cin >> id >> vs >> ts;
		if(vs >= h && ts >= h)
			sage.push_back(person(id, vs, ts));
		else {
			if(vs >= h && ts >= l)
				noble.push_back(person(id, vs, ts));
			else {
				if(vs >= l && vs < h && ts < h && ts >= l && ts <= vs)
					fool.push_back(person(id, vs, ts));
				else {
					if(vs >= l && ts >= l)
						small.push_back(person(id, vs, ts));
				}
			}
		}
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(small.begin(), small.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	cout << sage.size()+noble.size()+fool.size()+small.size() << endl;
	for(int i = 0; i < sage.size(); ++i)
		cout << sage[i];
	for(int i = 0; i < noble.size(); ++i)
		cout << noble[i];
	for(int i = 0; i < fool.size(); ++i)
		cout << fool[i];
	for(int i = 0; i < small.size(); ++i)
		cout << small[i];
	return 0;
}