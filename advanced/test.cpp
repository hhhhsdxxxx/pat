#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	set<int> test;
	test.insert(3);
	set<int>::iterator it = test.begin();
	test.insert(5);
	test.insert(4);
	test.erase(3);
	cout << *(it);
	return 0;
}