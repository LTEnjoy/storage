#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rank(int n[], int m)     //冒泡排序函数 
{
	int k;
	for(int j=m-1; j>0; j--)
		for(int i=0; i<j; i++)
			if(n[i] < n[i+1])
			{
				k = n[i];
				n[i] = n[i+1];
				n[i+1] = k;
			}
} 

void search(int num[],int b, int n)    //折半查找函数 
{
	int i;
	int a = 0; 
	while(1)
	{
		i = (a + b) / 2;
		if(n == num[i])
		{
			printf("数值%d在第%d位", n, i+1);
			break;
		}	
		if(n > num[i])
		{
			b = i;
		}
		if(n < num[i])
		{
			a = i;
		}
		if( b-a == 1)
		{
			if( n == num[a])
				printf("数值%d在第%d位", n, a + 1);
			if( n == num[b])
				printf("数值%d在第%d位", n, b + 1);
			else 
				printf("该数值不存在");
			break;
		}
	}
} 

int main()
{
	int num[1000];
	int i, n;
	srand(time(0));
	for(i=0; i<1000; i++)
	{	
   		num[i] = rand()%30000+1;
	}
	rank(num, 1000);
	for(i=0; i<1000; i++)
	{	
   		printf("%d\n", num[i]);
	}
	printf("已生成1000个有序数字请输入你要查找的数值（1~30000):"); 
	scanf("%d", &n);
	search(num, 999, n);
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
