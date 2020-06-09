#include <stdio.h>
int main()
{
	int n, i, j, k, l, m;
  	l = 0;
	printf("请输入有多少个数相加：");
	scanf("%d", &i);
	printf("\n请输入数字（0~9）："); 
	scanf("%d", &n);
 	for(i; i>0; i--)
 	{
 		 m = k = n;
		 for(j = 1;j < i; j++)
 		{
		 	 m *= 10;
     	 	 k += m;
 		}
 		l += k;
 		
	}
 	printf("输出的值是%d", l);
 	getchar();
} 
