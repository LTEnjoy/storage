#include <stdio.h>
int main()
{
	int n, i, j, k, l, m;
  	l = 0;
	printf("�������ж��ٸ�����ӣ�");
	scanf("%d", &i);
	printf("\n���������֣�0~9����"); 
	scanf("%d", &n);
 	for(i; i>0; i--)
 	{
 		 m = k = n;
		 for(j = 1;j < i; j++)
 		{
		 	 m *= 10;
     	 	 k += m;
 		}
 		l += k;
 		
	}
 	printf("�����ֵ��%d", l);
 	getchar();
} 
