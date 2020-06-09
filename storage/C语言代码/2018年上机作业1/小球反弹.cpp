#include <stdio.h>
 
int main()
{
	float n, i, j;
	n = 100;
	j = 0; 
	for(i=0; i<10; i++)
	{
		j += 2*n;
		n *= 0.5;
	}
	printf("一共经过%f米，第10次反弹%f米高", j-100, n);
	getchar(); 
}
