#include <stdio.h>

int main()
{
	char n, count;
	count = 0;
	printf("������һ��Ӣ�ģ�");
	while( (n = getchar()) != '\n')
		if(n>='A' && n<='Z' || n>='a' && n<='z')
		{
			count++;
			n = getchar();	
			while(n>='A' && n<='Z' || n>='a' && n<='z')
       		{
       			n = getchar(); 
       			if(n == 39)
       			{
       				count++; 
       				n = getchar();
       			}
       		}
       }
	printf("�⴮Ӣ����һ����%d������", count);
	printf("\n��q���˳�");
	while(getchar() != 'q')
		;
} 
