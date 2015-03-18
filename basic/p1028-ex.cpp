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
	person *total = new person[2];
	total[0].name = total[1].name = "";
	total[0].timer = 9999999;
	total[1].timer = 0;
	int year, month, day;
	string name;
	int timer;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		cin >> name;
		scanf("%d/%d/%d", &year, &month, &day);
		timer = year*1000 + month*31 + day;
		if(timer >= low_time && timer <= now_time){
			cnt++;
			if(timer > total[1].timer){
				total[1].name = name;
				total[1].timer = timer;
			}
			if(timer < total[0].timer){
				total[0].name = name;
				total[0].timer = timer;
			}
		}
	}
	cout << cnt;
	if(total[0].name != "")
		cout << " " << total[0].name << " " << total[1].name;
	return 0;
}