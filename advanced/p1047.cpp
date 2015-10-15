#include <iostream>
#include <vector>
// #include <algorithm>
#include <set>
#include <string>
#include <cstring>

using namespace std;

struct stu{
	char name[5];
	stu(char *_name){
		strcpy(name, _name);
	}
};

// ostream& operator<<(ostream &ou, stu &a){
// 	ou << a.name << endl;
// 	return ou;
// }

struct cmp : less<stu>{
	bool operator()(const stu a, const stu b) const{
		return strcmp(a.name, b.name) < 0;
	}
};

int main(){
	int n, k;
	cin >> n >> k;
	vector<set<stu, cmp>> coures(k, set<stu,cmp>());
	while(n--){
		char name[5];
		int cs;
		cin >> name >> cs;
		while(cs--){
			int cc;
			cin >> cc;
			coures[cc-1].insert(stu(name));
		}
	}
	for(int i = 0; i < coures.size(); ++i){
		cout << i+1 << " " << coures[i].size() << endl;
		for(set<stu, cmp>::iterator it = coures[i].begin(); it != coures[i].end(); ++it)
			cout << (*it).name << endl;
	}
	return 0;
}