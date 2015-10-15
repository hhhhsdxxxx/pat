#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 100001;

stack<int> st;
vector<int> t(MAXN, 0);

int lowbit(int k){
	return k&(-k);
}

void update(int pos, int d){
	while(pos <= MAXN){
		t[pos] += d;
		pos += lowbit(pos);
	}
}

int sum(int n){
	int s = 0;
	while(n > 0){
		s += t[n];
		n -= lowbit(n);
	}
	return s;
}

int find(int val, int l = 0, int h = MAXN-1){
	int mid = (l+h)/2;
	if(l == h)
		return l;
	int re = sum(mid);
	if(re < val)
		return find(val, mid+1, h);
	else
		return find(val, l, mid);
}

void do_pop(){
	if(st.empty())
		printf("Invalid\n");
	else {
		int k = st.top();
		printf("%d\n", k);
		update(k, -1);
		st.pop();
	}
}

void do_peek(){
	if(st.empty())
		puts("Invalid");
	else 
		printf("%d\n", find((st.size()+1)/2));
}

void do_push(int p){
	st.push(p);
	update(p, 1);
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char s[20];
		scanf("%s", s);
		if(s[1] == 'o')
			do_pop();
		else if(s[1] == 'e')
			do_peek();
		else if(s[1] == 'u'){
			int num;
			scanf("%d", &num);
			do_push(num);
		}
	}
	return 0;
}