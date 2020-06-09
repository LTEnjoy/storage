#include <stdio.h>

int main()
{
	int a;
	printf("请输入一个分数（0~100分）");
	scanf("%d", &a);
	if(a >= 90)
	printf("该分数得到成绩A");
	if(a >= 60 && a<89) 
	printf("该分数得到成绩B"); 
	if(a < 60)
	printf("该分数得到成绩C");  
	getchar(); 
}
