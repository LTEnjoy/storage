#include <stdio.h>

int main()
{
	int a;
	printf("������һ��������0~100�֣�");
	scanf("%d", &a);
	if(a >= 90)
	printf("�÷����õ��ɼ�A");
	if(a >= 60 && a<89) 
	printf("�÷����õ��ɼ�B"); 
	if(a < 60)
	printf("�÷����õ��ɼ�C");  
	getchar(); 
}
