#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define length 100
#define width 20

int judge;        //�жϺ�ʱ����̽·
					
void gotoxy(int x, int y)	//��꺯��
{   
    COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //����������ɫ
	return 0;
}

void give_num(int n[][length], int i, int j, int count)			//������������� 
{
	if(n[i][j] == 0)
	{
		n[i][j] = count;
		judge  = 1;
	} 
}

void sign(int n[][length], int i, int j, int count)       //�ڽڵ�������ɢ 
{
	give_num(n, i, j+1, count);
	give_num(n, i, j-1, count);
	give_num(n, i+1, j, count);
	give_num(n, i-1, j, count);
} 

int search(int n[][length], int i, int j)		//��ÿ���ڵ������� 
{
	int count = 1;
	while(n[width-1][length-2] == 0)
	{
		
		for(i=0; i<width; i++)					
			for(j=0; j<length; j++)
				if( n[i][j] == count)
					sign(n, i, j, count+1);
		if(judge == 0)
			break;
		judge = 0;
		count++;
 }
	return count;
}

void print(int n[][length], int i, int j, int count)  //��ӡ�Թ�·�� 
{
	color(50);
	if(judge == 0)
		if(n[i][j] == count)
		{
			gotoxy(j,i);
			printf(" ");
			if(i == 0 & j == 1)
				judge = 1;
			print(n, i-1, j, count-1); 
			print(n, i, j-1, count-1); 
			print(n, i, j+1, count-1); 
			print(n, i+1, j, count-1); 
		}
}

void barrier(int n[][length])      //��������ϰ��� 
{ 
	int i, j;
	srand(time(0));      
	int count = 0;     //����ָ���������ϰ���	
	while(count <= (width*length*3/5)) 
	{
		i = rand()%(width-2)+1;
		j = rand()%(length-2)+1;
		if(n[i][j] == 0)
			continue;
		else
		{
			n[i][j] = 0;
			count++;
		}
	}
} 

void graph(int n[][length]) 		//��ӡ����ʼ�Թ� 
{
	int i, j;
	for(i=0; i<width; i++)			//�Ƚ�����ȫ����ֵΪ-1
		for(j=0; j<length; j++)
			n[i][j] = -1;
	barrier(n);		//�ϰ��� 
	n[0][1] = 1; 
	n[width-1][length-2] = 0; //������ڳ��� 
	for(i=1; i<=3; i++)
		for(j=1; j<=3; j++)
			n[i][j] = n[width-i-1][length-j-1] = 0; 
	for(i=0; i<width; i++)				//��ӡ��ڳ��� 
	{
		for(j=0; j<length; j++)
			if( n[i][j] == -1)
				printf("#");
			else
				printf(" ");
		printf("\n");
	}
}

void quit() 		//�˳����� 
{
	gotoxy(0, width+1);
	color(7);
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;

}

int main()
{ 
	int i, j, count;
	int maze[width][length];
	graph(maze);				//��ӡ��ͼ 
	count = search(maze, 0, 1);	 //��¼��̲����� 
	if(maze[width-1][length-2] == 0)
		printf("\n���Թ�û��ͨ·");
	else 
		print(maze, width-1, length-2, count); //��ӡ�Թ�·��	
	quit();
}
