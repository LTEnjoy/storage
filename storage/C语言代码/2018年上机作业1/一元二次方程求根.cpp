#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, i, j, k;
	printf("����һԪ���η��� ax^2+bx+c=0����������Ӧ��ֵa, b, c����������ĸ���\n");
	printf("a:");
	scanf("%f", &a); 
	printf("b:");
	scanf("%f", &b); 
	printf("c:");
	scanf("%f", &c);
	i = b*b - 4*a*c;
	if(a < 1e-6 && a >=0)
		printf("�ⲻ��һԪ���η���"); 
	else
	{
		if(i > 1e-6)
			{
				k = (-b - sqrt(i))/(2*a);
				j = (-b + sqrt(i))/(2*a);
				printf("�÷��̵��������ֱ���%f��%f", j, k);
			}
		if(i < 1e-6 && i >= 0)
			{
				k = -b/(2*a);
				printf("�÷��̵ĸ���%f", k);
			}
		if(i<0)
			printf("�÷��̵��������ֱ���%f%fi��%f+%fi", -b/(2*a), -sqrt(-i)/(2*a), -b/(2*a), sqrt(-i)/(2*a));
		while(getchar() == '\n')
			;	
	}
}

 
