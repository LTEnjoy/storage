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
	printf("һ������%f�ף���10�η���%f�׸�", j-100, n);
	getchar(); 
}
