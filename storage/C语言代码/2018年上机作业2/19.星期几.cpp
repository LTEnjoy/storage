#include <stdio.h>

int main()
{
	char n;
	printf("���������ڼ��ĵ�һ����ĸ(�������д)��");
	scanf("%c", &n);
	while(n != 'M' && n != 'F' && n != 'T' && n != 'W' && n != 'S')
	{
		while(n = getchar() != '\n')
			; 
		printf("��������ȷ����ĸ��"); 
		scanf("%c", &n);
	}	 
	switch(n)
	{
		case'M':
			printf("��������һ"); 
			break;
		case'F':
			printf("����������"); 
			
			break;
		case'W':
			printf("����������"); 
			break;
		case'T':
			printf("���������ڼ��ĵڶ�����ĸ(�������д)��");
			while(n = getchar() != '\n')
				;
			scanf("%c", &n);
			while(n != 'H' && n != 'U')
			{
				printf("��������ȷ����ĸ��"); 
				while(n = getchar() != '\n')
					;
				scanf("%c", &n);
			}	 
			if(n == 'H')
			printf("����������");
			if(n == 'U')
			printf("�������ڶ�");
			break; 
		case'S':
			printf("���������ڼ��ĵڶ�����ĸ(������)��");
			while(n = getchar() != '\n')
				;
			scanf("%c", &n);
			while(n != 'A' && n != 'U')
			{
				while(n = getchar() != '\n')
					;
				printf("��������ȷ����ĸ��"); 
				scanf("%c", &n);
			}	 
			if(n == 'A')
			printf("����������");
			if(n == 'U')
			printf("����������");
			break; 
	}
	printf("\n��q���˳�");
	while(getchar() != 'q')
		;
} 
