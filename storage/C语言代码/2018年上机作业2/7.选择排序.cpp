#include <stdio.h>
#include <string.h>
/*����������  ���룺  AB	AAA		FWRW	WFWF	%@WE	!@FW	VWGQ	AAC		ABB		WEG 
  Ԥ�ڽ����  �����  !@FW  %@WE    AAA		AAC		AB		ABB		FWRW	VWGQ	WEG 	WFWF
  ʵ�ʽ����  �����  !@FW  %@WE    AAA		AAC		AB		ABB		FWRW	VWGQ	WEG 	WFWF	*/ 

char sign[10][20];         //ʮ���ַ�����Ϊȫ�ֱ��� 

void rank()     //ѡ������
{
	int i, j, k, t;		//k��Ϊ��� 
	char p[20];
	for(j=0; j<9; j++)
	{
		k = j;
		for(i=j; i<9; i++)
		{  
			for(t=0; t<20; t++)
				if(sign[k][t] > sign[i+1][t])
				{
					k = i+1;
					break;
				}
				else if(sign[k][t] == sign[i+1][t])
					continue;
				else if(sign[k][t] < sign[i+1][t])
					break;
		}
		if(k != j)
		{
			for(t=0; t<20; t++)
				p[t] = sign[j][t];
			for(t=0; t<20; t++)
			 {
			 	sign[j][t] = sign[k][t];
		   	 }
			for(t=0; t<20; t++)
				sign[k][t] = p[t];
		}
	}
} 

int main()
{
	int i;
	int b[10];
	
	printf("������10�����Ȳ�����20���ַ�����������\n");
	for(i=0; i<10; i++)
	{
		printf("�������%d���ַ���:", i+1);
		gets(sign[i]);
	} 
	rank();
	printf("��10���ַ������е�˳����:");
	for(i=0; i<10; i++)
		printf("\n%s", sign[i]); 
	
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
} 
