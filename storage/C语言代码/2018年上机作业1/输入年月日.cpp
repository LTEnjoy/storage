#include<stdio.h>
int main()
{
    int a, b, c, i, n;
    int judge = 0;
    n = 0;
	printf("������������\n");
	printf("��������ݣ�");
	scanf("%d", &a); 
	printf("�������·ݣ�");
	scanf("%d", &b);
	printf("�����뼸�գ�");
	scanf("%d", &c);
	if( (a%4 == 0 && a%100 != 0) || a%400 == 0)
		  judge = 1;
	for(i=1; i<b; i++)
	{
		if(i <= 7)
		{
			if(i%2 != 0)
				n += 31;
			else if(i%2 == 0)
			{
				if(i == 2 && judge == 1)
					n += 29;
				if(i == 2 && judge == 0)
					n += 28;
				if(i != 2)
					n += 30;
			}
		}
		if(i > 7)
		{
			if(i%2 != 0)
				n += 30;
			else
				n += 31;
		}
	}
	n += c;
	printf("����%d��ĵ�%d��", a, n); 
} 

