#include <stdio.h>

int main()
{
  	unsigned long long n, k;
	int i, j; 	
	n = 0;
	for(i=2; i<22; i++)
	{
		k = 1;
		for(j=1; j<i; j++)
		{
			k *= j;
		} 
		n += k;	
	}
	printf("求和的值是%llu", n);
	getchar();
} 
