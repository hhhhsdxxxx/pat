#include <iostream>

using namespace std;

int *stack, p = 0, MAX, top = 0;

bool push_to(int h){
	for(; top < MAX && p < h; ++top){
		// printf("push %d\n", p+1);
		stack[top] = ++p;
	}
	if(p < h)
		return 0;
	return 1;
}

int main(){
	int *s, n, k;
	cin >> MAX >> n >> k;
	while(k--){
		s = new int[MAX];
		p = 0;
		stack = s;
		top = 0;
		bool r = 1;
		int i;
		for(i = 0; i < n; ++i){
			int d;
			scanf("%d", &d);
			if(!r)
				continue;
			if(top > 0 && s[top-1] > d){
				puts("NO");
				r = 0;
			}
			else if(top > 0 && s[top-1] == d)
				--top;
			else if(top == 0 || s[top-1] < d){
				if(!push_to(d)){
					puts("NO");
					r = 0;
				}
				else
					--top;
			}
		}
		if(r)
			puts("YES");
		delete[] s;
	}
	return 0;
}