#include <stdio.h>

int main()
{
	char n, count;
	count = 0;
	printf("请输入一串英文：");
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
	printf("这串英文中一共有%d个单词", count);
	printf("\n按q键退出");
	while(getchar() != 'q')
		;
} 
