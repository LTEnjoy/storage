#include <stdio.h>


int main()
{
	char expre[20][20] = {0};   //�洢���ʽ 
  	int num[20] = {0};      //�洢ʵ�ʵ����� 
	int temp[20] = {0};      //����ʵ�����ֵ����� 
	int i = -1, j, k;          
	char n;
  	int count;
	printf("������һ�����ʽ��ֵ���������������Ҳ��ܳ������ţ���");
	while( (n = getchar()) != '\n')    //������ʽ 
	{
		if(n == ' ')
			continue;
		if(n >= '0' && n <= '9')
		{
			count = 0;
			i++;
			expre[i][count] = n;
			count++;
			n = getchar();
			while(n == ' ')
				n = getchar();
			while(n >= '0' && n <= '9')
			{
				expre[i][count] = n;
				count++;
				n = getchar();
				while(n == ' ')
					n = getchar();
			}
			for(j=0; j<count; j++)
			{
		  	    temp[i] = expre[i][j] - 48;
			    for(k=j; k<count-1; k++)
					temp[i] *=10;
				num[i] += temp[i] ;
			}
			i++;
			expre[i][0] = n;
		}
		if(n == '\n')
			break;
	}	
 	for(i=1; i<20; i+=2)
 	{
		 switch(expre[i][0])
 		{
 			case'*':num[i-1] *= num[i+1];
 					for(j=i; j<19; j++)
 						num[j] = num[j+2];  
					for(j=i; j<18; j+=2)	
 						expre[j][0] = expre[j+2][0];
					i -= 2;	  
 						break;
 			case'/':num[i-1] /= num[i+1];
 					for(j=i; j<19; j++)
 						num[j] = num[j+2];
					for(j=i; j<18; j+=2)	
 						expre[j][0] = expre[j+2][0];
					i -= 2;	    
 						break;
 			case'%':num[i-1] %= num[i+1];
 					for(j=i; j<19; j++)
 						num[j] = num[j+2];
					for(j=i; j<18; j+=2)	
 						expre[j][0] = expre[j+2][0];
					i -= 2;	    
 						break;
 		}
	}
	 for(i=1; i<20; i+=2)
 	{
 		
		switch(expre[i][0])
 		{
 			
			case'+':num[i-1] += num[i+1];
 					for(j=i+1; j<19; j+=2)
 						num[j] = num[j+2];
 					for(j=i; j<18; j+=2)	
 						expre[j][0] = expre[j+2][0];
					 i -= 2;
						break;
 		    case'-':num[i-1] -= num[i+1];
 					for(j=i; j<19; j++)
 						num[j] = num[j+2];
 					for(j=i; j<18; j+=2)	
 						expre[j][0] = expre[j+2][0];
					i -= 2;	    
 						break;
 		}
	}	
 	printf("��Ϊ%d", num[0]);
 	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
} 
