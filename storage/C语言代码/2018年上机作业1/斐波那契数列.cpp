#include <stdio.h>

int main()
{
	int i, j, n, k;
	i = j = 1;
	printf("第1月有1对兔子\n第2月有1对兔子\n"); 
	for(n = 3; n<30; n++)
	{
		k = j; 
		j = i + j;
		i = k; 
		printf("第%d月有%d对兔子\n", n, j);	
	}
	printf("·······");
	getchar();
} 
