#include <stdio.h>

int main()
{
	char  a, b, c;
	c = 'y';
	for(a='x'; a<='z'; a++)
	{
		if(a != 'x' && a != c)
			break;
	}
	for(b='x'; b<='z'; b++)
	{
		if(b != a && b != c)
			break;
	}
	printf("a与%c比赛，b与%c比赛，c与%c比赛", a, b, c);
	getchar();
} 
