#include <stdio.h>

int main()
{
	char n;
	printf("请输入星期几的第一个字母(请输入大写)：");
	scanf("%c", &n);
	while(n != 'M' && n != 'F' && n != 'T' && n != 'W' && n != 'S')
	{
		while(n = getchar() != '\n')
			; 
		printf("请输入正确的字母："); 
		scanf("%c", &n);
	}	 
	switch(n)
	{
		case'M':
			printf("这是星期一"); 
			break;
		case'F':
			printf("这是星期五"); 
			
			break;
		case'W':
			printf("这是星期三"); 
			break;
		case'T':
			printf("请输入星期几的第二个字母(请输入大写)：");
			while(n = getchar() != '\n')
				;
			scanf("%c", &n);
			while(n != 'H' && n != 'U')
			{
				printf("请输入正确的字母："); 
				while(n = getchar() != '\n')
					;
				scanf("%c", &n);
			}	 
			if(n == 'H')
			printf("这是星期四");
			if(n == 'U')
			printf("这是星期二");
			break; 
		case'S':
			printf("请输入星期几的第二个字母(请输入)：");
			while(n = getchar() != '\n')
				;
			scanf("%c", &n);
			while(n != 'A' && n != 'U')
			{
				while(n = getchar() != '\n')
					;
				printf("请输入正确的字母："); 
				scanf("%c", &n);
			}	 
			if(n == 'A')
			printf("这是星期六");
			if(n == 'U')
			printf("这是星期日");
			break; 
	}
	printf("\n按q键退出");
	while(getchar() != 'q')
		;
} 
