#include <stdio.h>
#define k 10

int jc(int n)     //����׳˺���
{
	int i, sum;
	sum = 1; 
	for(i=1; i<=n; i++)
	{
		sum *= i;
	}
	return sum;
} 

int func(int n, int m)       //����������Ϻ���
{
	int i;
	i = jc(m) / ( jc(m-n) * jc(n) );
	return i;
} 

int main()
{
	int n, m, sum;
	for(m=0; m<k; m++)
	{
		for(n=0; n<=m; n++)
		{
			sum = func(n,m);
			printf("%-5d", sum);
		}
		printf("\n");
	}
	getchar();
}
