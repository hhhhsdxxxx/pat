#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long long G, S, K, g, s, k;
	long long t0, t1, r0, r1, r2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &G, &S, &K, &g, &s, &k);
	t0 = G*17*29+S*29+K;
	t1 = g*17*29+s*29+k-t0;
	r0 = abs(t1%29);
	r1 = abs(t1/29%17);
	r2 = t1/29/17;
	printf("%lld.%lld.%lld", r2, r1, r0);
	return 0;
}