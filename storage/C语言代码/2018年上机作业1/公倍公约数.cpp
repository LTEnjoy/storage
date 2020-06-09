#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, i, j, m, n; 
	a = b = 0;
	printf("请输入两个正整数：\n");
	while(a == 0 || b == 0)
	{
		scanf("%d%d", &a, &b);
		if(a == 0 || b == 0)
			{
				printf("请输入两个正整数:\n");
				c = getchar();
			}
	}
	if(a<b)
    {
	    m = b; n = a;
    }
	else 
	{
		m = a; n = b;
	}  
    while(1)
	{
		 i = a%b;
		 if(i == 0)
		 	break;
		 else
		 {
		 	a = b; b = i;
		 }	
	}	   
	j = m*n/b;
	printf("它们的最大公约数是%d\n最小公倍数是%d", b, j);
    getch();
} 
