#include <stdio.h>

int main()
{
	int n, a, b, c, d;
	a = b = c = d =0;
	printf("������һ���ַ�:") ; 
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
	printf("һ����%d���ո�%d��Ӣ����ĸ��%d�����֣�%d�������ַ�", a, b, c, d);
	getchar();
} 
