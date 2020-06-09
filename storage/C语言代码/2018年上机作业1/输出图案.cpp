#include <stdio.h> 

int main()
{
	int i, j, k;
	j = 1;
	for(i=0; i<3; i++)
	{
		k = j;
		for(k; k>0; k--)
		{
			printf("*");
		}
		j += 2;
		printf("\n");
	}
	for(i=0; i<4; i++)
	{
		k = j;
		for(k; k>0; k--)
		{
			printf("*");
		}
		j -= 2;
		printf("\n");
	}
	getchar();
}
