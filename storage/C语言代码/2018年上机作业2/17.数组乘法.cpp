#include <stdio.h>

int main()
{
	int a[50] = {0};  //�����Ǹ����� 
	int b[50] = {0};
	int c[100] = {0};		//���֮��ķǸ�����
	int d[100] = {0};
	int e[50]; 		//���ڵ������������ֵ���ȷλ�� 
	int i = 0;
	int n;   //һλһλ�������� 
	int m,j;
	int r, q;  //����������֮��ļӷ�
	
	
	printf("��������������20λ������50λ�ķǸ����������λ��Ϊ0����\n");
	printf("�������һ���Ǹ�������");
	while( ( n = getchar() ) !=  '\n')
	{
		e[i] = n-48;
		i++; 
	}
	for(n=0; n<i; n++)
		a[n] = e[i-n-1];
	
	i = 0;
	printf("������ڶ����Ǹ�������");
	while( ( n = getchar() ) !=  '\n')
	{
		e[i] = n-48;
		i++;  
	}
	for(n=0; n<i; n++)
		b[n] = e[i-n-1];
	
	for(i=0; i<50; i++)	           //���˷��ֽ�������ӷ� 
	{
		r = 0; 
		for(n=0; n<50; n++)
		{
			
			q = (a[i]*b[n]+r) % 10;
			r =	(a[i]*b[n]+r) / 10;
			if(n == 49)
				c[50+i] = r;
			c[n+i] = q;
			
		}
		r = 0;
		for(m=0; m<100; m++)	
		{
			q = (c[m]+d[m]+r) % 10;
 			r = (c[m]+d[m]+r) / 10;
			d[m] = q; 
		}	
		for(j=0; j<100; j++)
			c[j] = 0;
	}
	
	
	printf("�˻�Ϊ");
	i = 0; 
	while( d[99-i] == 0)
	{
		i++;
	}
	for(i; i<100; i++)
	{
	
		printf("%d", d[99-i]);
	}
	
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
