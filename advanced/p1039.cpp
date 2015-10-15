#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// struct stu{
// 	char name[5];
// 	stu(char *_n){
// 		strcpy(name, _n);
// 	}
// 	stu(){}
// 	bool operator==(stu &a){
// 		return strcmp(name, a.name) == 0;
// 	}
// };

// struct m_less : less<stu>{
// 	bool operator()(const stu a, const stu b){
// 		return strcmp(a.name, b.name) < 0;
// 	}
// };

// int main(){
// 	map<stu, vector<int>, m_less> table;
// 	int n, k;
// 	cin >> n >> k;
// 	for(int i = 1; i <= k; ++i){
// 		int cid, snum;
// 		scanf("%d %d", &cid, &snum);
// 		while(snum--){
// 			stu tmp;
// 			scanf("%s", tmp.name);
// 			map<stu, vector<int>, m_less>::iterator it = table.find(tmp);
// 			if(it == table.end())
// 				table.insert(pair<stu, vector<int>>(tmp, vector<int>(1,cid)));
// 			else
// 				(it->second).push_back(cid);
// 		}
// 	}
// 	for(int i = 0; i < n; ++i){
// 		stu tmp;
// 		scanf("%s", tmp.name);
// 		map<stu, vector<int>, m_less>::iterator it = table.find(tmp);
// 		if(it != table.end()){
// 			printf("%s %d", tmp.name, it->second.size());
// 			sort(it->second.begin(), it->second.end());
// 			for(int j = 0; j < (it->second).size(); ++j)
// 				printf(" %d", (it->second)[j]);
// 			puts("");
// 		}
// 		else
// 			printf("%s 0\n", tmp.name);
// 	}

// 	return 0;
// }

vector<vector<int>> stu(26*26*26*10+10, vector<int>());

int cal(char *name){
	return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+name[3]-'0';
}

int main(){
	// map<stu, vector<int>, m_less> table;
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; ++i){
		int cid, snum;
		scanf("%d %d", &cid, &snum);
		while(snum--){
			char name[5];
			scanf("%s", name);
			stu[cal(name)].push_back(cid);
		}
	}
	for(int i = 0; i < n; ++i){
		char name[5];
		scanf("%s", name);
		int id = cal(name);
		printf("%s %d", name, stu[id].size());
		sort(stu[id].begin(), stu[id].end());
		for(int j = 0; j < stu[id].size(); ++j)
			printf(" %d", stu[id][j]);
		puts("");
	}

	return 0;
}