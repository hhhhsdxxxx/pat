#include <iostream>
#include <stdlib.h>

using namespace std;

struct student{
	char name[11];
	char sno[11];
	int score;
};

int comp(const void *a, const void *b){
	return ((student *)a)->score - ((student *)b)->score;
}

int main(){
	int n;
	cin >> n;

	struct student *stu;
	stu = new student[n];
	for(int i = 0; i < n; i++)
		cin >> stu[i].name >> stu[i].sno >> stu[i].score;
	qsort(stu, n, sizeof(stu[0]), comp);
	cout << stu[n-1].name << " " << stu[n-1].sno << endl
	     << stu[0].name   << " " << stu[0].sno   << endl;
}