#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

void simpler(long long *a, long long *b); 

void print_result(int flag, long long a, long long b, long long c)
{
	simpler(&a, &b);
	if(flag == 1)
		printf("(-");
	if(c==0 && a==0)
		printf("0");
	else if(c != 0)
	{
		c = (c<0)?(-c):c;
		printf("%lld", c);
		if(a != 0)
			printf(" %lld/%lld",a, b);
	}
	else if(c == 0)
	{
		printf("%lld/%lld", a, b);
	}
	if(flag == 1)
		printf(")");

}

long long max_comm(long a, long b)
{
	long long temp;
	
	if(a<b)
	{
		temp =a ;
		a = b;
		b = temp;
	}
	while(b!=0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
void simpler(long long *a, long long *b)
{
	long long x = *a<0?(-*a):*a;
	long long y = *b<0?(-*b):*b; 
	long long i = max_comm(x, y);
		
	while(x % i==0 && y % i ==0 && i!= 1)
	{
		x = x /i;
		y = y/i;
		i = max_comm(x,y);
	}
	
	*a = x;
	*b = y;
}

int main()
{
	long long a1,b1,c1,a2,b2,c2;
	int flag1=0,flag2=0;
	long long d1, d2, r;
	long long tt;
	string oper;
	long long i;
	
	oper.push_back('+');
	oper.push_back('-');
	oper.push_back('*');
	oper.push_back('/');
	
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	if(a1<0)
		flag1 = 1;
	c1 = a1/b1;
	tt = a1 % b1;
	a1 = tt<0?(-tt):tt;
		
	if(a2<0)
		flag2 = 1;
	c2 = a2/b2;
	tt = a2%b2;
	a2 = tt<0?(-tt):tt;
	
	for(i=0; i<4; i++)
	{
		long long q1,p1=b1,o1,q2,p2=b2,o2;
		int flag3 = 0;
		print_result(flag1, a1, b1, c1);
		printf(" %c ", oper[i]);
		print_result(flag2, a2, b2, c2);
		printf(" = ");

		if(flag1)
			q1 = c1*b1-a1;
		else
			q1 = c1*b1+a1;
		if(flag2)
			q2 = c2*b2-a2;
		else
			q2 = c2*b2+a2;
			
		switch(oper[i])
		{
			case '+':
				{
					long long x = p1 * p2;
					d2 = x;
					d1 = q1*x/p1 + q2*x/p2;
					if(d1<0)
						flag3 = 1;
					r = d1/d2;
					tt = d1 % d2;
					d1 = tt<0?(-tt):tt;
					break;
				}
			case '-':
				{
					long long x = p1 * p2;
					d2 = x;
					d1 = q1*x/p1 - q2*x/p2;
					if(d1<0)
						flag3 = 1;
					r = d1/d2;
					tt = d1 % d2;
					d1 = tt<0?(-tt):tt;
					break;
				}				
			case '*':
				{
					d2 = p1 * p2;
					d1 = q1 * q2;
					if(d1<0)
						flag3 = 1;
					r = d1/d2;
					tt = d1 % d2;
					d1 = tt<0?(-tt):tt;
					break;
				}				
			case '/':
				{
					if(q2 == 0)
					{
						printf("Inf\n");
						return 0;
					}
					d2 = p1 * q2;
					d1 = q1 * p2;
					if((d1<0 && d2>0) ||(d1>0 && d2<0))
						flag3 = 1;
					r = d1/d2;
					tt = d1 % d2;
					d1 = tt<0?(-tt):tt;
					d2 = (d2<0)?(-d2):d2;
					break;
				}			
			default:
				break;
		} 
		print_result(flag3, d1,d2,r);
		printf("\n");
	}
	
	return 0;
}
