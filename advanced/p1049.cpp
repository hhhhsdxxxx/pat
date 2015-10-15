#include <iostream>
#include <vector>

using namespace std;

int mypower(int n, int b = 10){
	if(!n)
		return 1;
	return b*mypower(n-1, b);
}

int fact(int n){
	if(n == 1 || n == 0)
		return 1;
	else
		return n*fact(n-1);
}

int C(int n, int m){
	return fact(n)/(fact(m)*fact(n-m));
}

int count(int wei, int n = 0){
	if(!n) {
		for(int i = 1; i <= wei; ++i)
			n += i*C(wei, i)*mypower(wei-i, 9);
	}
	else {
		vector<int> num;
		while(n){
			num.push_back(n%10);
			n /= 10;
		}
		while(!num.empty()){
			int top = num.back();
			num.pop_back();
			if(top == 1){
				int tmp = 0;
				for(int i = num.size()-1; i >= 0; --i)
					tmp = tmp*10+num[i];
				n += tmp+1;
			}
			for(int i = 0; i < top; ++i){
				if(i == 1)
					n += mypower(num.size())+count(num.size());
				else
					n += count(num.size());
			}
		}
		// cout << n << endl;
		// return n;
	}
	return n;
}

int main(){
	int n, w = 0;
	cin >> n;
	int tmp = n;
	while(tmp){
		++w;
		tmp /= 10;
	}
	tmp = count(w, n);
	// cout << count(1) << endl;
	cout << tmp;
	return 0;
}