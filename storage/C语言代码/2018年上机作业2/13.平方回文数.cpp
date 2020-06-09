#include <stdio.h>
#include <math.h>

int main()
{
	int num; 
	int a, b, c;  //代表百位，十位，个位
	int i, j; 
	printf("1-999的平方回文数是：\n");
	
	i = sqrt(9);
	for(num=1; num<=9; num++)
		for(j=1; j<=i; j++)
			if(j*j == num)
				printf("%d\n", num); 
	
	i = sqrt(99);
	for(a=1; a<=9; a++)
	{
		num = a*10 +a;
		for(j=1; j<=i; j++)
			if(j*j == num)
				printf("%d\n", num); 
	}
	
	i = sqrt(999);
	for(a=1; a<=9; a++)
		for(b=1; b<=9; b++)
		{
			num = a*100 + b*10 + a;
			for(j=1; j<=i; j++)
				if(j*j == num)
					printf("%d\n", num); 
		}		
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
} 
