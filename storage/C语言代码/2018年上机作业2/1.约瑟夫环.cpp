#include <stdio.h>
#include <stdlib.h>
#define size sizeof(struct num)

/*��������������������5,������3 
  Ԥ�ڽ������Ȧ�˵������ 3  1  5  2 
  ʵ�ʽ������Ȧ�˵������ 3  1  5  2 */  


struct num * p1, *p2, * p;				//����ȫ�ֱ���ָ�� 							    
int judge;								//�ж���ʱ����ѭ�� 				  
struct num
{
	int num;
	struct num * next;
	struct num * last;
};

void people(int n, int i)							//��β��ӵ�������Χ��һ��Ȧ 
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

void circulation(int m, int i)                 //��ʼ����
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
	printf("������������");
	scanf("%d", &n);
	judge = n;
	printf("�����뱨�����֣�");
	scanf("%d", &m);
	people(n, i);
	printf("��Ȧ���˰�˳��ֱ��ǣ�"); 
	while(judge != 1)
	{
		circulation(m, i); 
	}
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
} 
