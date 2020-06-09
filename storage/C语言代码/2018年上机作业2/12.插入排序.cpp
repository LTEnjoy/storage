#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Rank(int n[], int m, int t)  //冒泡插入排序函数 
{
	int i, j;
	for(i=0; i<=m; i++)
	{
		if(t >= n[i]) 
		{
			for(j=m; j>=i; j--)	
				n[j+1] = n[j];
			n[i] = t;
			break;
		}
	}
} 

int main()
{
	int num[1000];
	int rank[1000] = {0};
	int i, j, n;
	srand(time(0));
	for(i=0; i<1000; i++)	
   		num[i] = rand()%30000+1;
	for(i=0; i<1000; i++)
   		printf("%d\n", num[i]);
	printf("已生成1000个数字,按q进行插入排序：\n"); 
	while(getchar() != 'q')
	;
	for(j=0; j<1000; j++)
		Rank(rank, j, num[j]);	
	for(i=0; i<1000; i++)
   		printf("%d\n", rank[i]);
	printf("\n按q键退出");
	while(getchar() != 'q')
		;
} 
