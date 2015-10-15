#include <iostream>
#include <string>

using namespace std;

int to_upper(char ch){
	if(ch <= 'z' && ch >= 'a')
		ch = ch - 'a' + 'A';
	return (int)ch;
}

int index(int p, int *n){
	for(int i = 32; i < 128; ++i){
		if(n[i] == p)
			return i;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string ori, now;
	int cnt = 1;
	cin >> ori >> now;
	int sign_ori[128] = {0};
	int sign_now[128] = {0};
	for(int i = 0; i < ori.length(); ++i){
		if(ori.at(i)<0 || ori.at(i)>127)
			continue;
		if(sign_ori[to_upper(ori.at(i))] == 0){ 
			sign_ori[to_upper(ori.at(i))] = cnt;
			cnt++;
		}
	}
	for(int i = 0; i < now.length(); ++i){
		if(now.at(i)<0 || now.at(i)>127)
			continue;
		if(sign_now[to_upper(now.at(i))] == 0){
			sign_now[to_upper(now.at(i))] = 1;
		}
	}
	for(int i = 1; i < cnt; ++i){
		int k = index(i, sign_ori);
		if(sign_now[k] == 0)
			cout << (char)k;
	}
	return 0;
}