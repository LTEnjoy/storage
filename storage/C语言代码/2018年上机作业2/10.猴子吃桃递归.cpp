#include <stdio.h>

int number(int n, int i)
{
	i++;
	i *= 2;
	if(n < 9)
		number(n+1, i);
	if(n == 9)
		return i;	
} 

int main()
{
	printf("ԭ����%d������", number(1,1));
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
