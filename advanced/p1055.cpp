#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct person{
	string name;
	int age, netw;
	person():age(0),netw(0){name.resize(10);}
	bool isok(int l, int h){
		return age >= l && age <= h;
	}
};

bool cmp(const person &a, const person &b){
	if(a.netw != b.netw)
		return a.netw > b.netw;
	else {
		if(a.age != b.age)
			return a.age < b.age;
		else
			return a.name < b.name;
	}
}

ostream& operator<<(ostream &ou, person &a){
	ou << a.name << " " << a.age << " " << a.netw << endl;
	return ou; 
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<person> people(n, person());
	for(int i = 0; i < n; ++i){
		scanf("%s %d %d", &(people[i].name[0]), &(people[i].age), &(people[i].netw));
		int pos = people[i].name.find('\0');
		people[i].name = people[i].name.substr(0, pos);
		// people[i].name << name;
		// cin >> people[i].name >> people[i].age >> people[i].netw;
	}
	sort(people.begin(), people.end(), cmp);
	for(int i = 0; i < k; ++i){
		printf("Case #%d:\n", i+1);
		int ou, la, ha, p = 0, cnt = 0;
		scanf("%d %d %d", &ou, &la, &ha);
		while(cnt < ou && p < people.size()){
			if(people[p].isok(la, ha)){
				// cout << p << endl;
				cout << people[p];
				++cnt;
			}
			++p;
		}
		if(!cnt)
			puts("None");
	}
	return 0;
}