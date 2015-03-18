#include <iostream>

using namespace std;

bool isSame(int *a, int *b, int n){
	for(int i = 0; i < n; i++)
		if(a[i] != b[i])
			return false;
	return true;
}

bool isInsertSort(int *num, int n, int *half){
	bool isRight = false;
	for(int i = 0; i < n; i++){
		int t = num[i];
		int j;
		for(j = i-1; j >= 0 && num[j] > t; j--)
			num[j+1] = num[j];
		num[j+1] = t;
		if(isSame(num, half, n) && !isRight)
			isRight = true;
		else if(isRight && !isSame(num, half, n)) //****注意点*****
			return true;
	}
	return false;
}

void Merge(int *a, int n1, int n2){
	int i = 0;
	int j = n1;
	int *re = new int[n1+n2];
	for(int k = 0; k < n1+n2; k++){
		if(i < n1 && j < n1+n2){
			if(a[i] <= a[j]){
				re[k] = a[i];
				i++;
			}
			else{
				re[k] = a[j];
				j++;
			}
		}
		else if(i < n1){
			re[k] = a[i];
			i++;
		}
		else if(j < n1+n2){
			re[k] = a[j];
			j++;
		}
	}
	for(int k = 0; k < n1+n2; k++)
		a[k] = re[k];
	delete[] re;
	re = NULL;
}

bool isMergeSort(int *num, int n, int *half){
	int k = n;
	int i = 1;
	int j = 0;
	bool isRight = false;
	while(k != 0){
		j = 0;
		while(j < n){
			if((j+2*i) <= n)
				Merge(num+j, i, i);
			else if((j+i) < n && (j+2*i) > n)
				Merge(num+j, i, n-j-i);
			j += 2*i;
		}
		i *= 2;
		k /= 2;
		// for(int m = 0; m < n; m++){
		// 	if(m != 0) cout << " ";
		// 	cout << num[m];
		// }
		// cout << endl;
		if(!isRight && isSame(num, half, n))
			isRight = true;
		else if(isRight)
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int *num1, *num2, *half;
	int N, in;
	cin >> N;
	num1 = new int[N];
	num2 = new int[N];
	half = new int[N];
	for(int i = 0; i < N; i++){
		cin >> in;
		num1[i] = num2[i] = in;
	}
	for(int i = 0; i < N; i++)
		cin >> half[i];
	if(isInsertSort(num1, N, half))
		cout << "Insertion Sort" << endl;
	else if(isMergeSort(num2, N, half)){
		cout << "Merge Sort" << endl;
		for(int i = 0; i < N; i++)
			num1[i] = num2[i];	
	}
	for(int i = 0; i < N; i++){
		if(i != 0) cout << " ";
		cout << num1[i]; 
	}
	return 0;
}