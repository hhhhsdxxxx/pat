#include<cstdio>
#include<cstring>
using namespace std;

int a[100],b[100];
int N;
int flag = 0;

bool cmp(int *a, int *b)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

bool Insert_Sort(int *a)
{
	int i, j;
	int key, flag = 0;
	bool r = false;
	
	if(N == 1)
		return true;
	for(i=1;i<N;i++)
	{
		key = a[i];
		j = i - 1;
		while(j>=0&&a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		if(flag == 1)
		{
			return r;
		}
		if(cmp(a,b))
		{	
			r = true;
			flag = 1;
		}
	}
	return r;
}

bool Merge(int *c, int p, int q, int r, int n)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L1[n1], L2[n2];
	int i, j, k;
	bool re = false;
	
	n1 = q - p + 1;
	if(r > n-1)
		r = n-1;
	n2 = r - q;
	memcpy(L1, c+p, n1*sizeof(int));
	memcpy(L2, c+q+1, n2*sizeof(int));
	
	for(k=p,i=0,j=0; k<=r&&i<n1&&j<n2; k++)
	{
		if(L1[i] <= L2[j])
		{
			c[k] = L1[i];
			i++;
		}
		else
		{
			c[k] = L2[j];
			j++;
		}
	}
	if(i<n1)
	{
		memcpy(c+k, L1+i, (n1-i)*sizeof(int));
	}
	else
	{
		memcpy(c+k, L2+j, (n2-j)*sizeof(int));
	}
}

bool Merge_Sort(int* c, int length)
{
	int i, step = 1;
	bool result = false;
	
	while(step<length)
	{
		for(i=0; i<=length-step-1;i+= 2*step)
		{
			Merge(c, i, (i+i+2*step-1)/2, i+2*step-1, length);
		}
		 if(result == true)
			 return result;
		 if(cmp(a,b))
		 {
			 result = true;
		 }
		step = step * 2;
	}
	return result;
}

int main()
{
	int i;
	int c[100];
	scanf("%d", &N);
	int flag = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&b[i]);
	}
	memcpy(c,a,100*sizeof(int));
	
	if(Insert_Sort(c))
	{
		printf("Insertion Sort\n");
		memcpy(a,c,100*sizeof(int));
	}
	else 
	{
		if(Merge_Sort(a,N))
		{
			printf("Merge Sort\n");
		}
	}
	
	for(i=0; i<N; i++)
	{
		if(flag == 0)
		{
			flag = 1;
			printf("%d", a[i]);
		}
		else
		{
			printf(" %d", a[i]);
		}
	}
	printf("\n");
	
	return 0;
}
