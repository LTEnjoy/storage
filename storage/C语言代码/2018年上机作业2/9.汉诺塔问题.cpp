#include <stdio.h>

int times(int n)         //�ƶ� n������Ĵ���
{
	int i, num;
	num = 1;
	for(i=0; i<n; i++)
		num *= 2;
	num--;	
	printf("һ����Ҫ�ƶ�%d��\n", num);
} 

void tower(int n, char a, char b, char c)
{
	if(n>1)
		tower(n-1, a, c, b);
	printf("��%d��%c�Ƶ�%c\n", n, a, c);
	if(n>1)
		tower(n-1, b, a, c);
} 

int main()
{
	int n; 
	printf("�������̵ĸ�����");
	scanf("%d", &n);
	times(n);
	printf("������ԽС������ԽС���ƶ�����Ϊ��\n");
	tower(n, 'A', 'B', 'C');
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
