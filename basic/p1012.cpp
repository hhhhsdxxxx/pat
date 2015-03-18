#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int N, num;
	int A1, A2, A3, A5, A4, A4_num, temp;
	bool haveA2 = false;
	bool haveA1 = false;
	bool haveA3 = false;
	bool haveA4 = false;
	bool haveA5 = false;
	//double A4;
	cin >> N;
	A1 = A2 = A3 = A5 = A4_num = 0;
	A4 = 0.0;
	temp = 0;
	while(N--){
		cin >> num;
		if(num%5 == 0 && num%2 == 0){
			if(!haveA1)
				haveA1 = true;
			A1 += num;
		}
		else if(num%5 == 1){
			if(!haveA2)
				haveA2 = true;
			A2 += ((temp % 2 == 0) ? num : (-1*num));
			temp++;
		}
		else if(num%5 == 2){
			if(!haveA3)
				haveA3 = true;
			A3++;
		}
		else if(num%5 == 3){
			if(!haveA4)
				haveA4 = true;
			A4_num++;
			A4 += num;
		}
		else if(num%5 == 4){
			if(!haveA5)
				haveA5 = true;
			if(num > A5)
				A5 = num;
		}
	}
	if(!haveA1)
		cout << "N ";
	else
		cout << A1 << " ";
	if(haveA2)
		cout << A2 << " ";
	else
		cout << "N ";
	if(!haveA3)
		cout << "N ";
	else
		cout << A3 << " ";
	if(!haveA4)
		cout << "N ";
	else
		printf("%.1lf ", double(1.0*A4/A4_num));
		// cout << setiosflags(ios::fixed) << setprecision(1) << double(A4/A4_num) << " ";
	if(!haveA5)
		cout << "N";
	else
		cout << A5;  
	return 0;
}
