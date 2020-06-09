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
	printf("原来有%d个桃子", number(1,1));
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
