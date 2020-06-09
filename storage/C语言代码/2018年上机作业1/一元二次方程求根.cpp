#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, i, j, k;
	printf("对于一元二次方程 ax^2+bx+c=0，请输入相应的值a, b, c，以求出它的根：\n");
	printf("a:");
	scanf("%f", &a); 
	printf("b:");
	scanf("%f", &b); 
	printf("c:");
	scanf("%f", &c);
	i = b*b - 4*a*c;
	if(a < 1e-6 && a >=0)
		printf("这不是一元二次方程"); 
	else
	{
		if(i > 1e-6)
			{
				k = (-b - sqrt(i))/(2*a);
				j = (-b + sqrt(i))/(2*a);
				printf("该方程的两个根分别是%f和%f", j, k);
			}
		if(i < 1e-6 && i >= 0)
			{
				k = -b/(2*a);
				printf("该方程的根是%f", k);
			}
		if(i<0)
			printf("该方程的两个根分别是%f%fi和%f+%fi", -b/(2*a), -sqrt(-i)/(2*a), -b/(2*a), sqrt(-i)/(2*a));
		while(getchar() == '\n')
			;	
	}
}

 
