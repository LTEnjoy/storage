#include <stdio.h>

int main()
{
	int a[3][3];
	int i, j;
	printf("�����������9��������ÿ��3����\n");
	for(i=0; i<3; i++)
	{
		printf("�������%d�е����֣�", i+1);
		for(j=0; j<3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	} 
	for(i=0; i<3; i++)
	{
			if(a[i][0]<a[i][1] && a[i][1]<a[i][2])
			printf("�þ����ڵ�%d�е���\n", i+1);
			else
			printf("�þ����ڵ�%d�в�����\n", i+1); 
	} 
	for(j=0; j<3; j++)
	{
			if(a[0][j]<a[1][j] && a[1][j]<a[2][j])
			printf("�þ����ڵ�%d�е���\n", j+1);
			else 
			printf("�þ����ڵ�%d�в�����\n", j+1);
	} 
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
} 
