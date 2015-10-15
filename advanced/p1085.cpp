#include <iostream>
#include <algorithm>

using namespace std;

bool is_suitable(int min, int max, int p){
	if(max/min == p && max%min == 0 || max/min < p)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int N, p;
	cin >> N >> p;
	int *num = new int[N];
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num+N);
	int cnt = 0, ptr = 0;
	while(cnt < N-ptr){
		int l = ptr, h = N;
		while(l < h-1){
			if(is_suitable(num[ptr], num[(h+l)/2], p))
				l = (h+l)/2;
			else
				h = (h+l)/2;
		}
		if(cnt < l+1-ptr)
			cnt = l+1-ptr;
		ptr++;
	}
	cout << cnt;
	return 0;
}