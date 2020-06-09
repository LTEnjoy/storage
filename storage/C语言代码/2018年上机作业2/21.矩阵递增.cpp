#include <stdio.h>

int main()
{
	int a[3][3];
	int i, j;
	printf("请分三行输入9个整数，每行3个：\n");
	for(i=0; i<3; i++)
	{
		printf("请输入第%d行的数字：", i+1);
		for(j=0; j<3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	} 
	for(i=0; i<3; i++)
	{
			if(a[i][0]<a[i][1] && a[i][1]<a[i][2])
			printf("该矩阵在第%d行递增\n", i+1);
			else
			printf("该矩阵在第%d行不递增\n", i+1); 
	} 
	for(j=0; j<3; j++)
	{
			if(a[0][j]<a[1][j] && a[1][j]<a[2][j])
			printf("该矩阵在第%d列递增\n", j+1);
			else 
			printf("该矩阵在第%d列不递增\n", j+1);
	} 
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
} 
