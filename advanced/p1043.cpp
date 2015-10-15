#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator pint;

int value = 0;
vector<int> ans;
bool re = 1;

bool cmp1(int i){
	return i < value;
}

bool cmp2(int i){
	// cout << i << endl;
	return i >= value;
}

void istree(pint begin, pint end, bool (*cmp)(int)){
	if(begin == end)
		return;
	value = *begin;
	// cout << value << endl;
	pint r = find_if(begin+1, end, cmp);
	if(!all_of(r, end, cmp)){
		// cout << value << endl;
		re = 0;
		return;
	}
	if(!re)
		return;
	istree(begin+1, r, cmp);
	istree(r, end, cmp);
	ans.push_back(*begin);
}

int main(){
	int n;
	cin >> n;
	bool (*cmp)(int) = cmp2;
	vector<int> tree(n, 0);
	for(int i = 0; i < n; ++i)
		scanf("%d", &tree[i]);
	if(n > 1 && tree[0] <= tree[1])
		cmp = cmp1;
	istree(tree.begin(), tree.end(), cmp);
	if(re){
		puts("YES");
		for(int i = 0; i < ans.size(); ++i){
			if(i)
				printf(" ");
			printf("%d", ans[i]);
		}
	}
	else
		puts("NO");
	return 0;
}