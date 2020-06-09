#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rank(int n[], int m)     //ð�������� 
{
	int k;
	for(int j=m-1; j>0; j--)
		for(int i=0; i<j; i++)
			if(n[i] < n[i+1])
			{
				k = n[i];
				n[i] = n[i+1];
				n[i+1] = k;
			}
} 

void search(int num[],int b, int n)    //�۰���Һ��� 
{
	int i;
	int a = 0; 
	while(1)
	{
		i = (a + b) / 2;
		if(n == num[i])
		{
			printf("��ֵ%d�ڵ�%dλ", n, i+1);
			break;
		}	
		if(n > num[i])
		{
			b = i;
		}
		if(n < num[i])
		{
			a = i;
		}
		if( b-a == 1)
		{
			if( n == num[a])
				printf("��ֵ%d�ڵ�%dλ", n, a + 1);
			if( n == num[b])
				printf("��ֵ%d�ڵ�%dλ", n, b + 1);
			else 
				printf("����ֵ������");
			break;
		}
	}
} 

int main()
{
	int num[1000];
	int i, n;
	srand(time(0));
	for(i=0; i<1000; i++)
	{	
   		num[i] = rand()%30000+1;
	}
	rank(num, 1000);
	for(i=0; i<1000; i++)
	{	
   		printf("%d\n", num[i]);
	}
	printf("������1000������������������Ҫ���ҵ���ֵ��1~30000):"); 
	scanf("%d", &n);
	search(num, 999, n);
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
