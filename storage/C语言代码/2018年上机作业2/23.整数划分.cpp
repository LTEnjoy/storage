#include <stdio.h>

int sum, count;

void shrink(int num[], int n)     //整数划分函数 
{
	int i;
	for(i=1; i<=n; i++)
	{
		sum += i;
		num[count] = i;
		count++;
		if(sum < n)
		{
			shrink(num, n);
		}
		if(sum == n)
		{
			int judge = 0;
			int i, j; 
			for(i=count-1; i>0; i--)
				for(j=0; j<i; j++)
					if(num[j] > num[i])
					{
						judge = 1;
					}
			if(judge == 0)
			{	
				printf("%d=", n);
				for(j=0; j<count; j++)
					printf("%d+",num[j]);
				printf("\b \n");
			}
			count--;
			sum -= num[count] + num[count-1];
			count--; 
			break;
		}	
	}
}


int main()
{
	int n;
	printf("请输入一个整数进行整数划分：");
	scanf("%d", &n); 
	int num[n];
	shrink(num, n);
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
