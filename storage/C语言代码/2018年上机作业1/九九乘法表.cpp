#include <stdio.h>

int main()
{
	int i, j;
	printf("�žų˷���\n"); 
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
