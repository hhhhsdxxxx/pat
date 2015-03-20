#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	if(N == 1){
		cout << "0";
		return 0;
	}
	int end, cnt, max, tmp;
	cnt = max = 0;
	tmp = N;
	for(int i = 2; i < sqrt(N)+10; i++){
		if(tmp%i==0){
			cnt++;
			tmp /= i;
		}
		else {
			if(cnt > max){
				max = cnt;
				end = i;
			}
			i = i-cnt;
			cnt = 0;
			tmp = N;
		}
	}
	if(max != 0){
		cout << max << endl;
		bool f = true;
		for(int i = end-max; i < end; i++){
			if(!f)
				cout << "*";
			f = false;
			cout << i;
		}
	}
	else {
		cout << "1" << endl << N;
	}
	return 0;
}