#include <stdio.h>

int main()
{
	float stu[4][5];
	int i;
	float score;
	printf("����������ѧ���ĳɼ�\n");
	printf("      ����   	 ��ѧ       Ӣ��    	���� \n");
	for(i=0; i<3; i++)
	{
		printf("ѧ��%d:", i+1);
		scanf("%f %f %f %f", &stu[i][0], &stu[i][1], &stu[i][2], &stu[i][3]);
		stu[i][4] = (stu[i][0]+stu[i][1]+stu[i][2]+stu[i][3])/4;
	}
	for(i=0; i<=4; i++)
		stu[3][i] = (stu[0][i]+stu[1][i]+stu[2][i])/3;
	printf("      		����  	  	��ѧ        Ӣ��   	  ����         ƽ���ɼ�\n");
	for(i=0; i<3; i++)
	{
		printf("ѧ��%d:		%g    %g    %g    %g   %g\n", i+1, stu[i][0], stu[i][1], stu[i][2], stu[i][3], stu[i][4]);
	}
	printf("ƽ���ɼ���	%g    %g    %g    %g   %g\n", stu[3][0], stu[3][1], stu[3][2], stu[3][3], stu[3][4]);
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
