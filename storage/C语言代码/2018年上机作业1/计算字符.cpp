#include <stdio.h>

int main()
{
	int n, a, b, c, d;
	a = b = c = d =0;
	printf("请输入一行字符:") ; 
	while( (n = getchar() ) != '\n')
	{
	   if(n == ' ')
	   	a++;
	   else if( (n >= 'A' && n <= 'Z') || n >= 'a' && n <='z' )  
	   	b++;
	   else if(n >= '0' && n <= '9')
	   	c++;	
	   else
	   	d++;	
	}
	printf("一共有%d个空格，%d个英文字母，%d个数字，%d个其它字符", a, b, c, d);
	getchar();
} 
