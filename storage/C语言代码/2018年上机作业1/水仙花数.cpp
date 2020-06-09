#include<stdio.h>

int main()
{
	int a, b, c;
	int num;
	printf("100~999中所有的水仙花数是：\n");
	for(a=1; a<10; a++)
		{
			for(b=0; b<10; b++) 
				{
					for(c=0; c<10; c++)
						{
							num = a*100 + b*10 + c;
							if(num == a*a*a + b*b*b + c*c*c)
						 		printf("%d\n", num);
						}
				}
		}
	getchar();
} 
