#include <iostream>

using namespace std;

int two_same(char *ch1, char *ch2){
	int first, second;
	first = second = 0;
	for(int i = 0; ch1[i] != 0 && ch2[i] != 0; i++){
		if(ch1[i] == ch2[i]){
			if(first == 0 && ch1[i] >= 'A' && ch1[i] <= 'G'){
				first = int(ch1[i]);
				continue;
			}
			if(first != 0 && second == 0 && (ch1[i] >= 'A' && ch1[i] <= 'N' || ch1[i] >= '0' && ch1[i] <= '9')){
				second = int(ch1[i]);
				break;	
			}
		}
	}
	// cout << first << " " << second << endl;
	return first | (second << 8);
}

int seconds(char *ch1, char *ch2){
	for(int i = 0; ch1[i] != 0 && ch2[i] != 0; i++)
		if(ch1[i] == ch2[i] && (ch1[i] >= 'a' && ch1[i] <= 'z' || ch1[i] >= 'A' && ch2[i] <= 'Z'))
			return i;
	return -1;
}

int main(){
	char str[4][61];
	char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	for(int i = 0; i < 4; i++)
		cin >> str[i];
	int k = two_same(str[0], str[1]);
	int second = seconds(str[2], str[3]);
	char d = char(k&0xff);
	char hour_str = char(k>>8);
	int hour = ((hour_str >= 'A') ? int(10+hour_str-'A'):int(hour_str-'0'));
	// cout << d - 'A' << endl;
	// cout << hour << endl;
	cout << day[int(d-'A')] << " "; 
	cout << hour/10 << hour%10; 
	cout << ":" << second/10 << second%10;

	return 0;
}