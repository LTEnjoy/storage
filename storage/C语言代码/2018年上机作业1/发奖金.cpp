#include <stdio.h>
int main()
{
	long i, bonus;
	printf("请输入一个以元为单位的整数金额：");
	scanf("%d", &i);
	if(i<=100000) 
		bonus = i*0.1;
	if(i>100000 && i<=200000)	
		bonus = 10000 + (i-100000)*0.075;
	if(i>200000 && i<=400000)
		bonus = 17500 + (i-200000)*0.05;
	if(i>400000 && i<=600000)
		bonus = 27500 + (i-400000)*0.03;		
	if(i>600000 && i<=1000000)
		bonus = 33500 + (i-600000)*0.015;
	if(i>1000000)
		bonus = 39500 + (i-1000000)*0.01;
	printf("应发奖金总数为%d", bonus);	
	printf("\n按q键退出");
	while(getchar() != 'q')
	;		
} 
