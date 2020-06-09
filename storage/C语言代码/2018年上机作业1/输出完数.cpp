#include <stdio.h>
#include <math.h>

int main()
{
	int num, i, j, a;
	num = 1;
	printf("1~1000中所有的完数是；\n1\n"); 
	while(num <=1000)
	{
		a = 0;
		i = 1;
		j = sqrt(num);
		for(i; i<=j; i++)
		   {
		   	 if(num%i == 0)
		   	 {	 
				if(i*i != num) 	 
					a += i + num/i;
			 	else
			 		a += i;
		     }		   
		   }
	    if(num == a - num)
	    	printf("%d\n", num);
	    num++;
	}
	getchar();
} 
