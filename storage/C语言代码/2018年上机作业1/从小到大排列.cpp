#include <stdio.h>

int main()
{
	int x, y, z, i;
	i = 3;
	printf("����������������\n");
	scanf("%d %d %d", &x, &y, &z);
	if(x>y)
	{
		i = x;
		x = y;
		y = i;
	}
	if(x>z)
	{
		i = x;
		x = z;
		z = i;
	}
	if(y>z)
	{
		i = y;
		y = z;
		z = i;
	}
	printf("����������С����������%d %d %d", x, y, z);
	getchar();
} 
