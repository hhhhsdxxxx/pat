#include <iostream>
#include <string>

using namespace std;

char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
	string l1, l2, l3, l4;
	cin >> l1 >> l2 >> l3 >> l4;
	int ptr = 0;
	int _day, h, s = 0;
	while(ptr < l1.length() && ptr < l2.length()){
		if(l1[ptr] == l2[ptr] && l1[ptr] <= 'G' && l2[ptr] >= 'A'){
			_day = l1[ptr]-'A';
			break;
		}
		ptr++;
	}
	ptr++;
	while(ptr < l1.length() && ptr < l2.length()){
		if(l1[ptr] == l2[ptr] && (l1[ptr] <= 'N' && l2[ptr] >= 'A' || l1[ptr] <= '9' && l1[ptr] >= '0')){
			if(l1[ptr] < 'A')
				h = l1[ptr]-'0';
			else
				h = l1[ptr]-'A'+10;
			break;
		}
		ptr++;
	}
	ptr = 0;
	while(ptr < l3.length() && ptr < l4.length()){
		if(l3[ptr] == l4[ptr] && (l3[ptr] <= 'Z' && l3[ptr] >= 'A' || l3[ptr] <= 'z' && l3[ptr] >= 'a'))
			break;
		ptr++;
	}
	s = ptr;
	printf("%s %02d:%02d", day[_day], h, s);
	return 0;
}