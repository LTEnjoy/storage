#include <stdio.h>

int times(int n)         //移动 n个所需的次数
{
	int i, num;
	num = 1;
	for(i=0; i<n; i++)
		num *= 2;
	num--;	
	printf("一共需要移动%d次\n", num);
} 

void tower(int n, char a, char b, char c)
{
	if(n>1)
		tower(n-1, a, c, b);
	printf("把%d从%c移到%c\n", n, a, c);
	if(n>1)
		tower(n-1, b, a, c);
} 

int main()
{
	int n; 
	printf("请输入盘的个数：");
	scanf("%d", &n);
	times(n);
	printf("（数字越小代表盘越小）移动方法为：\n");
	tower(n, 'A', 'B', 'C');
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
