#include <stdio.h>

int main()
{
   int n = 1;
   int i;
   for(i = 0; i<9; i++)
   {	
		n++;
		n *= 2;
   } 
   printf("原来有%d个桃子", n);
   getchar() ;
} 
