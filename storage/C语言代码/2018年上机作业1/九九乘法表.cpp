#include <stdio.h>

int main()
{
	int i, j;
	printf("¾Å¾Å³Ë·¨±í£º\n"); 
	for(j=1; j<10; j++)
	{
		printf("\n");
		for(i=1; i<10; i++)
		{
			printf("%d*%d=%-5d", j, i, i*j);
		}
	}
	getchar(); 
}
