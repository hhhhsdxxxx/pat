#include <iostream>
#include <cmath>

using namespace std;

int to_hash(int *table, int key, int size){
	int k = 0;
	while(k<size && table[(key+k*k)%size] != -1)
		k++;
	if(k == size)
		return -1;
	table[(key+k*k)%size] = key;
	return (key+k*k)%size;
}

bool is_prime(int k){
	if(k < 2)
		return false;
	if(k == 2)
		return true;
	for(int i = 2; i < sqrt(k)+2; ++i)
		if(k%i == 0)
			return false;
	return true;
}

int find_prime(int k){
	while(!is_prime(k))
		k++;
	return k;
}

int main(int argc, char const *argv[])
{
	int msize, tsize, n, *htable;
	cin >> msize >> n;
	tsize = find_prime(msize);
	htable = new int[tsize];
	bool f = true;
	for(int i = 0; i < tsize; ++i)
		htable[i] = -1;
	while(n--){
		int in;
		cin >> in;
		if(!f)
			cout << " ";
		else
			f = false;
		int re = to_hash(htable, in, tsize);
		if(re != -1)
			cout << re;
		else
			cout << "-";
	}
	return 0;
}