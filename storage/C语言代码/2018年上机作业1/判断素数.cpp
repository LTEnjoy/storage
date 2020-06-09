#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, i, j, a;
	num = 101;
	while(num <=200)
	{
		a = 1;
		i = 2;
		j = sqrt(num);
		for(i; i<=j; i++)
		   {
		   	 if(num%i == 0)
		   	   {
		   	 	 a = 0;
		   	 	 break;
		       }
		   }
		if(a == 1)
		   printf("%d不是素数\n", num);
		if(a == 0)
		   printf("%d是素数\n", num);
	    num++;
	}
	getchar(); 
}
