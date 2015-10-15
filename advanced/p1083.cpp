#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct stu_grade{
	string name, id;
	int grade;

	stu_grade():name(""),id(""),grade(0){}

};

bool cmp(stu_grade a, stu_grade b){
	if(a.grade != b.grade)
		return a.grade > b.grade;
	else{
		if(a.name != b.name)
			return a.name < b.name;
		else
			return a.id < b.id;
	}	
}

bool is_in(int g, int l, int h){
	return g>=l && g<=h;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	stu_grade *stu = new stu_grade[N];
	for(int i = 0; i < N; ++i)
		cin >> stu[i].name >> stu[i].id >> stu[i].grade;
	sort(stu, stu+N, cmp);
	int l, h;
	cin >> l >> h;
	if(l > h){
		int tmp = h;
		h = l;
		l = tmp;
	}
	if(stu[0].grade<l || stu[N-1].grade>h)
		cout << "NONE";
	else{
		for(int i = 0; i < N; ++i){
			if(is_in(stu[i].grade, l, h))
				cout << stu[i].name << " " << stu[i].id << endl;
		}
	}
	return 0;
}