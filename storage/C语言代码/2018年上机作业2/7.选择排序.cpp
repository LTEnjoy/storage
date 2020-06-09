#include <stdio.h>
#include <string.h>
/*测试用例：  输入：  AB	AAA		FWRW	WFWF	%@WE	!@FW	VWGQ	AAC		ABB		WEG 
  预期结果：  输出：  !@FW  %@WE    AAA		AAC		AB		ABB		FWRW	VWGQ	WEG 	WFWF
  实际结果：  输出：  !@FW  %@WE    AAA		AAC		AB		ABB		FWRW	VWGQ	WEG 	WFWF	*/ 

char sign[10][20];         //十组字符串作为全局变量 

void rank()     //选择排序
{
	int i, j, k, t;		//k作为标记 
	char p[20];
	for(j=0; j<9; j++)
	{
		k = j;
		for(i=j; i<9; i++)
		{  
			for(t=0; t<20; t++)
				if(sign[k][t] > sign[i+1][t])
				{
					k = i+1;
					break;
				}
				else if(sign[k][t] == sign[i+1][t])
					continue;
				else if(sign[k][t] < sign[i+1][t])
					break;
		}
		if(k != j)
		{
			for(t=0; t<20; t++)
				p[t] = sign[j][t];
			for(t=0; t<20; t++)
			 {
			 	sign[j][t] = sign[k][t];
		   	 }
			for(t=0; t<20; t++)
				sign[k][t] = p[t];
		}
	}
} 

int main()
{
	int i;
	int b[10];
	
	printf("请输入10个长度不超过20的字符串进行排序\n");
	for(i=0; i<10; i++)
	{
		printf("请输入第%d个字符串:", i+1);
		gets(sign[i]);
	} 
	rank();
	printf("这10个字符串排列的顺序是:");
	for(i=0; i<10; i++)
		printf("\n%s", sign[i]); 
	
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
} 
