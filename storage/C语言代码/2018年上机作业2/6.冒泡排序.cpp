#include <stdio.h>

/*测试用例：   输入：1	   23	 124   32	 425  3	   563	36	 68	 467
  预期结果：   输出：563   467   425   124   68   36   32   23   3   1 
  实际结果：   输出：563   467   425   124   68   36   32   23   3   1*/
   
int rank(int n[], int m)     //排序函数 
{
	int k;
	for(int j=m-1; j>0; j--)
		for(int i=0; i<j; i++)
			if(n[i] < n[i+1])
			{
				k = n[i];
				n[i] = n[i+1];
				n[i+1] = k;
			}
} 

int main()
{
	int i, j, k,a[10];
	printf("请输入10个整数进行大小排序\n");
	for(i=0; i<10; i++)
	{
		printf("请输入第%d个数", i+1); 
		scanf("%d", &a[i]);
	} 
	rank(a, 10);
	printf("这10个数由大到小排列的顺序是：");
	for(i=0; i<10; i++)
	{		
		printf("%d   ", a[i]); 
	}
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
	
}
 
