#include<stdio.h>
int main()
{
    int a, b, c, i, n;
    int judge = 0;
    n = 0;
	printf("请输入年月日\n");
	printf("请输入年份：");
	scanf("%d", &a); 
	printf("请输入月份：");
	scanf("%d", &b);
	printf("请输入几日：");
	scanf("%d", &c);
	if( (a%4 == 0 && a%100 != 0) || a%400 == 0)
		  judge = 1;
	for(i=1; i<b; i++)
	{
		if(i <= 7)
		{
			if(i%2 != 0)
				n += 31;
			else if(i%2 == 0)
			{
				if(i == 2 && judge == 1)
					n += 29;
				if(i == 2 && judge == 0)
					n += 28;
				if(i != 2)
					n += 30;
			}
		}
		if(i > 7)
		{
			if(i%2 != 0)
				n += 30;
			else
				n += 31;
		}
	}
	n += c;
	printf("这是%d年的第%d天", a, n); 
} 

