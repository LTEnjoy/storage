#include <stdio.h>

int main()
{
	int i, j, n, k;
	i = j = 1;
	printf("��1����1������\n��2����1������\n"); 
	for(n = 3; n<30; n++)
	{
		k = j; 
		j = i + j;
		i = k; 
		printf("��%d����%d������\n", n, j);	
	}
	printf("��������������");
	getchar();
} 
