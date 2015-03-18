#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int C1, C2;
	const int CLK_TCK = 100;

	cin >> C1 >> C2;
	int seconds = (C2-C1)/CLK_TCK + (((C2-C1)%CLK_TCK >= 50) ? 1 : 0);
	int second = seconds%60;
	int minute = seconds/60%60;
	int hour   = seconds/3600;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return 0;
}