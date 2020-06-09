#include <stdio.h>

unsigned long long jc(int n)     //定义阶乘函数 
{
	unsigned long long i, sum;
	sum = 1; 
	for(i=1; i<=n; i++)
	{
		sum *= i;
	}
	return sum;
}

unsigned long long Sum_jc(int i, unsigned long long sum)
{
	sum += jc(i);
	if(i<20)
		Sum_jc(i+1, sum);
	if(i == 20)
		return sum;
} 

int main()
{
	int i;
	unsigned long long sum = 0;
	for(i=1; i<=20; i++)
		sum += jc(i);
	printf("1+2!+3!+...+20!的和为%llu(循环算法)\n\n", sum); 
	
	

	printf("1+2!+3!+...+20!的和为%llu(递归算法)", Sum_jc(1,0)); 
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}  
