#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

struct student{
	int name;
	int dscore;
	int cscore;
	int L;
};

int comp(const void *a, const void *b){
	student *p1 = (student *)a;
	student *p2 = (student *)b;
	if((p1->dscore + p1->cscore) != (p2->dscore + p2->cscore))
		return (p2->dscore + p2->cscore - p1->dscore - p1->cscore);
	else{
		if(p1->dscore != p2->dscore)
			return p2->dscore - p1->dscore;
		else
			return p1->name - p2->name;
	}
}

void copy(int i, int j, student *stu1, student *stu2){
	stu1[i].name = stu2[j].name;
	stu1[i].dscore = stu2[j].dscore;
	stu1[i].cscore = stu2[j].cscore;
	stu1[i].L = stu2[j].L;
}

int main(){
	int N, L, H;
	cin >> N >> L >> H;
	struct student *stu;
	stu = new student[N];
	int L1, L2, L3, L4;
	L1 = L2 = L3 = L4 = 0;

	for(int i = 0; i < N; i++){
		cin >> stu[i].name >> stu[i].dscore >> stu[i].cscore;
		stu[i].L = 0;
		if(stu[i].dscore >= H){
			if(stu[i].cscore >= H){
				L1++;
				stu[i].L = 1;
			}
			else if(stu[i].cscore >= L){
				L2++;
				stu[i].L = 2;
			}
		}
		else if(stu[i].dscore >= L){
			if(stu[i].dscore >= stu[i].cscore){
				L3++;
				stu[i].L = 3;
			}
			else{
				L4++;
				stu[i].L = 4;
			}
		}
	}
	int cnt1, cnt2, cnt3, cnt4;
	cnt1 = cnt2 = cnt3 = cnt4 = 0;
	student *re = new student[L1+L2+L3+L4];
	for(int i = 0; i < N; i++){
		if(stu[i].L == 1){
			copy(cnt1, i, re, stu);
			cnt1++;
		}
		else if(stu[i].L == 2){
			copy(cnt2+L1, i, re, stu);
			cnt2++;
		}
		else if(stu[i].L == 3){
			copy(cnt3+L1+L2, i, re, stu);
			cnt3++;
		}
		else if(stu[i].L == 4){
			copy(cnt4+L1+L2+L3, i, re, stu);
			cnt4++;
		}
	}
	int size = sizeof(stu[0]);
	if(L1 != 0)
		qsort(re, L1, size, comp);
	if(L2 != 0)
		qsort(re+L1, L2, size, comp);
	if(L3 != 0)
		qsort(re+L1+L2, L3, size, comp);
	if(L4 != 0)
		qsort(re+L1+L2+L3, L4, size, comp);
	for(int i = 0; i < L1 + L2 + L3 + L4; i++){
		cout << re[i].name << " " << re[i].dscore << " " << re[i].cscore << endl;
	}
	return 0;
}