#include <stdio.h>

int main()
{
	int i, j;
	printf("打印国际象棋棋盘："); 
	for(j=1; j<9; j++)
	{
		printf("\n");
		for(i=1; i<9; i++)
		{
			if( (i+j) % 2 == 0)
				printf("■");
			else
				printf("□");
		}
	} 
	getchar();
}
