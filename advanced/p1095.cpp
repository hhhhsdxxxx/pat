/*
临界点的问题，比如00:00:00的进车
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct in{
	int time;
	string id;
	string state;
	// bool operator<(const in& A){
	// 	return time < A.time;
	// }
};

bool comp1(in a, in b){
	return a.time < b.time;
}

struct record{
	int time_in;
	int time_out;
	string id;
	bool in;
	record() :time_in(-1), time_out(0){
		id = "";
		in = false;
	}

	// bool operator<(const record &A){
	// 	return (time_out != -1 && ((time_out == A.time_out) ? (id < A.id) : (time_out > A.time_out)));
	// }
};

bool comp2(record a, record b){
	return (a.time_out != -1 && ((a.time_out == b.time_out) ? (a.id < b.id) : (a.time_out > b.time_out)));
}

class allrecord{
	int n, size;
	record *all;
	int *allday;
public:
	allrecord(int n) :size(0){
		this->n = n;
		all = new record[n];
		allday = new int[3600 * 24];
		for (int i = 0; i < 3600 * 24; i++)
			allday[i] = 0;
	}

	int contains(string name){
		for (int i = 0; i < size; i++)
			if (all[i].id == name)
				return i;
		return -1;
	}

	void add(int ptime, string name, string state){
		if (state == "in"){
			int k = contains(name);
			if (k == -1){
				all[size].id = name;
				all[size].time_in = ptime;
				all[size].in = true;
				size++;
			}
			else{
				all[k].time_in = ptime;
				all[k].in = true;
			}
			
		}
		else if (state == "out"){
			int k = contains(name);
			if (k == -1)
				return;
			else{
				if (all[k].in){
					all[k].time_out += ptime - all[k].time_in;
					allday[ptime]--;
					allday[all[k].time_in]++;
					all[k].in = false;
				}
			}
		}
	}

	void check(){
		for (int i = 0; i < size; i++){
			if (all[i].time_out == -1)
				allday[all[i].time_in]--;
		}
	}

	void sort(){
		std::sort(all, all + size, comp2);
	}

	int ptimes(int f, int time1, int time2){
		int cnt = 0;
		for (int i = time1+1; i <= time2; i++)
			if (allday[i] != 0)
				cnt += allday[i];
		cout << f+cnt << endl;
		return f + cnt;
	}

	void pcars(){
		sort();
		int max = all[0].time_out;
		string former = all[0].id;
		cout << former << " ";
		for (int i = 1; i < size; i++){
			if (all[i].time_out < max)
				break;
			if (all[i].time_out == max){
				cout << all[i].id << " ";
				former = all[i].id;
			}
		}
		int hour = all[0].time_out / 3600;
		int min = all[0].time_out % 3600 / 60;
		int sec = all[0].time_out % 60;
		printf("%02d:%02d:%02d", hour, min, sec);
	}

	~allrecord(){
		delete[] all;
		all = NULL;
		delete[] allday;
		allday = NULL;
	}
};



int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;
	in *input = new in[N];
	for (int i = 0; i < N; i++){
		cin >> input[i].id;
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		input[i].time = hour * 3600 + min * 60 + sec;
		cin >> input[i].state;
	}
	sort(input, input + N, comp1);
	allrecord whole(N);
	for (int i = 0; i < N; i++){
		whole.add(input[i].time, input[i].id, input[i].state);
	}
	whole.check();
	int ftime = -1;
	int ptime = 0;
	int k = 0;
	for (int i = 0; i < K; i++){
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		ptime = hour * 3600 + min * 60 + sec;
		k = whole.ptimes(k, ftime, ptime);
		ftime = ptime;
	}
	whole.pcars();
	return 0;
}