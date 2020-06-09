#include <stdio.h>

int main()
{
	int a, b, c, i, num;
	i = 0; 
	printf("这些数字分别是：\n");
	for(a=1; a<5; a++)
		{
			for(b=1; b<5; b++)
			{
				for(c=1; c<5; c++)
				{
					num = a*100 + b*10 + c;
					if ( a!=b && b!=c && a!=c)
						{
							printf("%d\n", num);
							i++;
						}
				}
			}
		}
	printf("一共有%d个数字", i);
} 
