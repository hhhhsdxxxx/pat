#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct sname{
	char name[9]; 
};

struct stu{
	int id, score;
	sname name;
	stu():id(0),score(0){}
};

bool cmp3(const stu& a, const stu& b){
	if(a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}

bool cmp2(const stu& a, const stu& b){
	int r = strcmp(a.name.name, b.name.name);
	if(r)
		return r < 0;
	return a.id < b.id;
}

bool cmp1(const stu& a, const stu& b){
	return a.id < b.id;
}

int main(){
	int n, c;
	cin >> n >> c;
	vector<stu> student(n, stu());
	bool (*cmp)(const stu&, const stu&);

	switch(c){
		case 1: cmp = cmp1; break;
		case 2: cmp = cmp2; break;
		case 3: cmp = cmp3; break;
		default: cmp = cmp3; break;
	}
	for(int i = 0; i < n; ++i)
		cin >> student[i].id >> student[i].name.name >> student[i].score;
	if(c > 3 || c < 1)
		return 0;
	sort(student.begin(), student.end(), cmp);
	for(int i = 0; i < n; ++i)
		printf("%06d %s %d\n", student[i].id, student[i].name.name, student[i].score);
	return 0;
}