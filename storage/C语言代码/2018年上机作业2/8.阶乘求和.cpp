#include <stdio.h>

unsigned long long jc(int n)     //����׳˺��� 
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
	printf("1+2!+3!+...+20!�ĺ�Ϊ%llu(ѭ���㷨)\n\n", sum); 
	
	

	printf("1+2!+3!+...+20!�ĺ�Ϊ%llu(�ݹ��㷨)", Sum_jc(1,0)); 
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}  
