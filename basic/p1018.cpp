#include <iostream>

using namespace std;

int main(){
	int N, jc, jj, jb, yc, yj, yb, s, p, f;
	char j, y;
	jc = jj = jb = yc = yb = yj = s = p = f = 0;
	cin >> N;
	while(N--){
		cin >> j >> y;
		if(j == y)
			p++;
		else{ 
			if(j == 'C'){
				if(y == 'J'){
					s++;
					jc++;
				}
				else{
					f++;
					yb++;
				}
			}
			else if(j == 'J'){
				if(y == 'C'){
					f++;
					yc++;
				}
				else{
					s++;
					jj++;
				}
			}
			else if(j == 'B'){
				if(y == 'C'){
					s++;
					jb++;
				}
				else{
					f++;
					yj++;
				}
			}
		}
	}
	cout << s << " " << p << " " << f << endl
		 << f << " " << p << " " << s << endl;
	if(jb >= jc && jb >= jj)
		cout << "B";
	else if(jc >= jb && jc >= jj)
		cout << "C";
	else
		cout << "J";
	cout << " ";
	if(yb >= yc && yb >= yj)
		cout << "B";
	else if(yc >= yb && yc >= yj)
		cout << "C";
	else
		cout << "J";
	return 0;
}