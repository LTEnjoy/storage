#include <stdio.h>

/*����������   ���룺1	   23	 124   32	 425  3	   563	36	 68	 467
  Ԥ�ڽ����   �����563   467   425   124   68   36   32   23   3   1 
  ʵ�ʽ����   �����563   467   425   124   68   36   32   23   3   1*/
   
int rank(int n[], int m)     //������ 
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

int main()
{
	int i, j, k,a[10];
	printf("������10���������д�С����\n");
	for(i=0; i<10; i++)
	{
		printf("�������%d����", i+1); 
		scanf("%d", &a[i]);
	} 
	rank(a, 10);
	printf("��10�����ɴ�С���е�˳���ǣ�");
	for(i=0; i<10; i++)
	{		
		printf("%d   ", a[i]); 
	}
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
	
}
 
