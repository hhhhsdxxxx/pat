#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, D;
	cin >> A >> B >> D;
    vector<int> v;
    int op = A + B;
    while(op != 0){
    	v.push_back(op%D);
    	op /= D;
    }
    if(!v.empty())
    	for(vector<int>::iterator it = v.end()-1; it >= v.begin(); it--)
    		cout << *it;
    else
    	cout << "0";
	return 0;
}