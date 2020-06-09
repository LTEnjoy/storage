#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define length 100
#define width 20

int judge;        //判断何时结束探路
					
void gotoxy(int x, int y)	//光标函数
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
	return 0;
}

void give_num(int n[][length], int i, int j, int count)			//广度搜索标记序号 
{
	if(n[i][j] == 0)
	{
		n[i][j] = count;
		judge  = 1;
	} 
}

void sign(int n[][length], int i, int j, int count)       //在节点四周扩散 
{
	give_num(n, i, j+1, count);
	give_num(n, i, j-1, count);
	give_num(n, i+1, j, count);
	give_num(n, i-1, j, count);
} 

int search(int n[][length], int i, int j)		//将每个节点标上序号 
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

void print(int n[][length], int i, int j, int count)  //打印迷宫路线 
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

void barrier(int n[][length])      //随机生成障碍物 
{ 
	int i, j;
	srand(time(0));      
	int count = 0;     //生成指定数量的障碍物	
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

void graph(int n[][length]) 		//打印出初始迷宫 
{
	int i, j;
	for(i=0; i<width; i++)			//先将数组全部赋值为-1
		for(j=0; j<length; j++)
			n[i][j] = -1;
	barrier(n);		//障碍物 
	n[0][1] = 1; 
	n[width-1][length-2] = 0; //设置入口出口 
	for(i=1; i<=3; i++)
		for(j=1; j<=3; j++)
			n[i][j] = n[width-i-1][length-j-1] = 0; 
	for(i=0; i<width; i++)				//打印入口出口 
	{
		for(j=0; j<length; j++)
			if( n[i][j] == -1)
				printf("#");
			else
				printf(" ");
		printf("\n");
	}
}

void quit() 		//退出界面 
{
	gotoxy(0, width+1);
	color(7);
	printf("\n按q键退出");
	while(getchar() != 'q')
	;

}

int main()
{ 
	int i, j, count;
	int maze[width][length];
	graph(maze);				//打印地图 
	count = search(maze, 0, 1);	 //记录最短步骤数 
	if(maze[width-1][length-2] == 0)
		printf("\n该迷宫没有通路");
	else 
		print(maze, width-1, length-2, count); //打印迷宫路线	
	quit();
}
