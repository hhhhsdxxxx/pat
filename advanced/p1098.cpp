#include <iostream>

using namespace std;

bool cmp(int *a, int *b, int size){
	while(--size>=0){
		if(a[size] != b[size])
			return false;
	}
	return true;
}

bool isinsort(int *s, int *t, int N){
	bool right = false;
	for(int i = 0; i < N; i++){
		for(int j = i - 1; j >= 0; j--){
			if(s[j]>s[i]){
				int tmp = s[j];
				s[j] = s[i];
				s[i] = tmp;
				i = j;
			}
			else{
				break;
			}
		}
		if(cmp(s, t, N) && !right)
			right = true;
		else if(right && !cmp(s, t, N))
			return true;
	}
	return false;
}

void adjustheap(int *s, int size, int p){
	int i = p;
	do{
		int h = s[i];
		int l = i*2+1<size?i*2+1:i;
		int r = l+1<size?l+1:i;
		int index = s[l]>s[r]?l:r;
		int max = s[index];
		if(h<max){
			s[i] = max;
			s[index] = h;
			i = index;
		}
		else
			break;
	}while(i*2+1<size || i*2+2<size);
}

bool ishsort(int *s, int *t, int N){
	//build heap
	bool right = false;
	for(int i = N/2-1; i >= 0; i--){
		adjustheap(s, N, i);
	}
	if(cmp(s, t, N) && !right)
		right = true;
	for(int i = N-1; i>0; i--){
		int tmp = s[0];
		s[0] = s[i];
		s[i] = tmp;
		adjustheap(s, i, 0);
		if(cmp(s, t, N) && !right)
			right = true;
		else if(!cmp(s, t, N) && right)
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int *s, *t, *c;
	int N;
	cin >> N;
	s = new int[N];
	t = new int[N];
	c = new int[N];
	for(int i = 0; i < N; i++)
		cin >> s[i];
	for(int i = 0; i < N; i++)
		cin >> t[i];
	for(int i = 0; i < N; i++)
		c[i] = s[i];
	if(isinsort(s, t, N)){
		cout << "Insertion Sort" << endl;
		for(int i = 0; i < N; i++){
			if(i != 0)
				cout << " ";
			cout << s[i];
		}
	}
	else if(ishsort(c, t, N)){
		cout << "Heap Sort" << endl;
		for(int i = 0; i < N; i++){
			if(i != 0)
				cout << " ";
			cout << c[i];
		}
	}
	return 0;
}