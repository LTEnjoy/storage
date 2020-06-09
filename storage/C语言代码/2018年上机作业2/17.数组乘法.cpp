#include <stdio.h>

int main()
{
	int a[50] = {0};  //两个非负整数 
	int b[50] = {0};
	int c[100] = {0};		//相乘之后的非负整数
	int d[100] = {0};
	int e[50]; 		//用于调节数组中数字的正确位置 
	int i = 0;
	int n;   //一位一位输入数字 
	int m,j;
	int r, q;  //负责辅助数组之间的加法
	
	
	printf("请输入两个超过20位不超过50位的非负整数（最高位不为0）；\n");
	printf("请输入第一个非负整数：");
	while( ( n = getchar() ) !=  '\n')
	{
		e[i] = n-48;
		i++; 
	}
	for(n=0; n<i; n++)
		a[n] = e[i-n-1];
	
	i = 0;
	printf("请输入第二个非负整数：");
	while( ( n = getchar() ) !=  '\n')
	{
		e[i] = n-48;
		i++;  
	}
	for(n=0; n<i; n++)
		b[n] = e[i-n-1];
	
	for(i=0; i<50; i++)	           //将乘法分解成许多个加法 
	{
		r = 0; 
		for(n=0; n<50; n++)
		{
			
			q = (a[i]*b[n]+r) % 10;
			r =	(a[i]*b[n]+r) / 10;
			if(n == 49)
				c[50+i] = r;
			c[n+i] = q;
			
		}
		r = 0;
		for(m=0; m<100; m++)	
		{
			q = (c[m]+d[m]+r) % 10;
 			r = (c[m]+d[m]+r) / 10;
			d[m] = q; 
		}	
		for(j=0; j<100; j++)
			c[j] = 0;
	}
	
	
	printf("乘积为");
	i = 0; 
	while( d[99-i] == 0)
	{
		i++;
	}
	for(i; i<100; i++)
	{
	
		printf("%d", d[99-i]);
	}
	
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
