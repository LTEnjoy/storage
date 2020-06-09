#include <stdio.h>

int main()
{
	char n;
	printf("ÇëÊäÈëÒ»´®Ó¢ÎÄ×ÖÄ¸:\n");
	while(1)
	  	{
	  		n = getchar();
	  		if( n<'A' || n>'z' || (n>'Z' && n <'a') )
	  		{
	  			putchar(n);
	  			continue;
	  		}
	  		else if( (n<'W' && n>='A') || (n>='a' && n<'w') )
				n += 4;
			else 
				n -= 22; 
			printf("%c",n);
		}
}
 
