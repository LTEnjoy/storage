#include <stdio.h>

int main()
{
	float stu[4][5];
	int i;
	float score;
	printf("请输入三名学生的成绩\n");
	printf("      语文   	 数学       英语    	理综 \n");
	for(i=0; i<3; i++)
	{
		printf("学生%d:", i+1);
		scanf("%f %f %f %f", &stu[i][0], &stu[i][1], &stu[i][2], &stu[i][3]);
		stu[i][4] = (stu[i][0]+stu[i][1]+stu[i][2]+stu[i][3])/4;
	}
	for(i=0; i<=4; i++)
		stu[3][i] = (stu[0][i]+stu[1][i]+stu[2][i])/3;
	printf("      		语文  	  	数学        英语   	  理综         平均成绩\n");
	for(i=0; i<3; i++)
	{
		printf("学生%d:		%g    %g    %g    %g   %g\n", i+1, stu[i][0], stu[i][1], stu[i][2], stu[i][3], stu[i][4]);
	}
	printf("平均成绩：	%g    %g    %g    %g   %g\n", stu[3][0], stu[3][1], stu[3][2], stu[3][3], stu[3][4]);
	printf("\n按q键退出");
	while(getchar() != 'q')
	;
}
