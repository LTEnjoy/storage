#include <stdio.h>

int main()
{
	float i, j, k, n, t;
	i = 1;
	j = 2;
	n = 0; 
	for(t=0; t<20; t++)
	{
		n += j/i;
		k = j;
		j = i + j;
		i = k;
	}
	printf("������ǰ��ʮ���Ϊ%f", n);
	getchar();
} 
