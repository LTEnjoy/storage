#include <stdio.h>
int main()
{
	int i, j, k, n;
	k = 2;
	n = 0;
	printf("������һ�����������ֽ���������");
	scanf("%d", &i);
	printf("%d=", i);
	j = i*0.5;
		for(k ; k<=j; k++)
		   {
		   	 if(i%k == 0)
		   	   {
		   	 	 i /= k;
				 printf("%d*", k);
				 k = 1;
				 n = 1;
		       }
		   } 
	if(n == 0)
		printf("%d*", i);
	printf("\b ");
	getchar(); 
} 

