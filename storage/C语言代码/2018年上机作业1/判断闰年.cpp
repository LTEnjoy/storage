#include <stdio.h>

void function(int n)
{
	static int sum = 0;
	if (n > 1)
		sum += function(n - 1);
	if(n!=1)
	return n*n;
}

int main()
{
	int i;
	scanf("%d", &i);
	printf("%d", function(i));
	getchar(); 
	getchar(); 
}
