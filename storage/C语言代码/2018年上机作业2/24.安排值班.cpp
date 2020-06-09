#include<stdio.h>
#define A order[0] 
#define B order[1]
#define C order[2] 
#define D order[3]
#define E order[4] 
#define F order[5] 
#define G order[6] 

int main()
{
	int order[7] = {0};	//由题目可判断 C大夫比 F大夫晚值班， B大夫比 F大夫早值班 
	int i;
	F = 4;
	for(C=5; C<7; C++) 
	{
			A = C+1;
		for(B=3; B>1; B--)
		{
			if(B+3 == C || B+3 == F || B+3 == A)
				continue;
			else 
				G = B + 3;
			for(i=1; i<4; i++)
			{
				if(i == B)
					continue;
				else
					E = i;
				if(A+B+C+G+E+F+E+2 == 28)
					{
						D = E+2;
						for(i=0;i<7; i++)
							printf("%c大夫在第%d天值班\n", i+'A', order[i]);
					}
			}
		}
	} 
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
