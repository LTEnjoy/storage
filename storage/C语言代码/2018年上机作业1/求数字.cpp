#include <stdio.h>
#include <math.h>

int main()
{
 	
 	int i, n, j, k;
	n = sqrt(100000); 
	printf("这个数是");
	for(i=1; i<100001; i++)
	{
		for(k=11; k<n; k++)
		{
			j = i + 100; 
			if(k*k == j)
			{
				j = i + 268;
				for(k=11; k<n; k++)
				{
					if (k*k == j)
						printf("%d   ", i);
				}
			}
		}
	}
	getchar();
} 
