#include <stdio.h>

#define queenNumber 8  

int queen[queenNumber][queenNumber] = {0};
int count = 0;
int num = 0;

void print()  //打印国际象棋盘
{
	int i, j;
	for(i=0; i<queenNumber; i++)
	{
		 for(j=0; j<queenNumber; j++)
		{
			if(queen[i][j] == 0)
				printf("□");
			else
				printf("●");
		}
		printf("\n");
	}
	printf("\n\n");
	num++;
} 

void SetQueen(int j)
{	
	int i, k, m, judge; 								//m k负责判断皇后放置的位置是否符合要求 
		for(i=0; i<queenNumber; i++)
		{
			judge = 0;
			k = j-1;
			while(k>=0)
			{
				if(queen[k][i] == 1)
					{	judge = 1;
						break;	  }
				k--;
			}
			if(judge == 1)
				continue;
			k = j-1;
			m = i-1;
			while(k>=0 && m>=0)
			{
				if(queen[k][m] == 1)
					{	judge = 1;
						break;	  }
				k--;
				m--;
			}
			if(judge == 1)
				continue;
			k = j-1;
			m = i+1;
			while(m < queenNumber && k>=0)
			{
				if(queen[k][m] == 1)
					{	judge = 1;
						break;	  }
				k--;
				m++;
			}
			if(judge == 1)
				continue;
			queen[j][i] = 1;
			count++;
			if(count == queenNumber)
				print();
			if(j < queenNumber-1)
				SetQueen(j+1);
			for(int m=0; m<queenNumber; m++)
				queen[j][m] = 0;
			count--;
		}
}

int main()
{

	SetQueen(0); 
	printf("一共有%d种排列方法,如上所示；\n", num);
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
} 
