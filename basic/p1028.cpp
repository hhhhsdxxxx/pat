#include <iostream>
#include <string>

using namespace std;

struct person{
	string name;
	int timer;
};

int main(int argc, char const *argv[])
{
	const int now_time = 2014*1000+9*31+6;
	const int low_time = 1814*1000+9*31+6;
	int N;
	cin >> N;
	person *total = new person[N];
	int year, month, day;
	for(int i = 0; i < N; i++){
		cin >>  total[i].name;
		scanf("%d/%d/%d", &year, &month, &day);
		total[i].timer = year*1000 + month*31 + day;
	}
	int cnt = 0;
	int max, min, min_ID, max_ID;
	max = 0;
	min_ID = max_ID = -1;
	min = 9999999;
	for(int i = 0; i < N; i++){
		if(total[i].timer <= now_time && total[i].timer >= low_time){
			cnt++;
			if(total[i].timer > max){
				max = total[i].timer;
				max_ID = i;
			}
			if(total[i].timer < min){
				min = total[i].timer;
				min_ID = i;
			}
		}
	}
	cout << cnt;
	if(min_ID != -1)
	 	cout << " " <<total[min_ID].name << " " << total[max_ID].name;
	return 0;
}