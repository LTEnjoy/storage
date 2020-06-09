#include <stdio.h>
#include <stdlib.h>
#define size sizeof(struct num)

/*测试用例：输入人数：5,报数：3 
  预期结果：出圈人的序号是 3  1  5  2 
  实际结果：出圈人的序号是 3  1  5  2 */  


struct num * p1, *p2, * p;				//定义全局变量指针 							    
int judge;								//判定何时结束循环 				  
struct num
{
	int num;
	struct num * next;
	struct num * last;
};

void people(int n, int i)							//首尾相接的链表将人围成一个圈 
{
	p = p1 = (struct num *)malloc(size);
	p1->num = 1;
	for(i=1; i<n; i++)
	{
		p2 = (struct num *)malloc(size);
		p1->next = p2;
		p2->last = p1;
		p1 = p2;
		p1->num = i+1;
	}
	p1->next = p;
	p->last = p1;
	p1 = p;
}

void circulation(int m, int i)                 //开始报数
{
	for(i=1; i<m; i++)
	{
		p1 = p1->next;
	}
	p2 = p1->last;
	p2->next = p1->next;
	p2 = p1->next;
	p2->last = p1->last;
	printf("%d   ", p1->num);
	p1 = p1->next;
	judge--; 
} 

int main()
{
	int n, m, i;
	printf("请输入人数：");
	scanf("%d", &n);
	judge = n;
	printf("请输入报的数字：");
	scanf("%d", &m);
	people(n, i);
	printf("出圈的人按顺序分别是："); 
	while(judge != 1)
	{
		circulation(m, i); 
	}
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
} 
