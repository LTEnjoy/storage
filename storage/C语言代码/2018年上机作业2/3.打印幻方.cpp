#include <stdio.h>

/*����������    ����  n=3,				n=4,  						n=6�� 
  Ԥ�ڽ���� 	8   1   6			16  2   3   13			35  1   6   26  19  24
				3	5	7			5   11  10  8			3   32  7   21  23  25
				4	9	2			9   7   6   12			31  9   2   22  27  20
									4   14  15  1			8   28  33  17  10  15
															30  5   34  12  14  16
															4   36  29  13  18  11
				
  ʵ�ʽ����	8   1   6			16  2   3   13			35  1   6   26  19  24
				3   5   7			5   11  10  8			3   32  7   21  23  25
				4   9   2			9   7   6   12			31  9   2   22  27  20
 									4   14  15  1			8   28  33  17  10  15
															30  5   34  12  14  16
															4   36  29  13  18  11	*/ 
int main()
{
	int n, i, j;
	printf("������һ����n��");
	scanf("%d", &n); 
	
	
	int a[n][n];       //Ϊ���鸳��ֵ0 
	for(j=0; j<n; j++)
		for(i=0; i<n; i++)
			a[j][i] = 0;
			
			
	if(n%2 != 0)		//�����׻÷� 
	{
		int k, i0, j0;		//i0�� j0��¼i,jԭ����λ�� 
		i = n/2;
		j = 0;
		for(k=1; k<=n*n; k++)
		{
			a[j][i] = k;
			i0 = i;
			j0 = j;
			if(j==0 && i==n-1)			//�ж��Ƿ�λ�ڻ÷����Ͻ� 
				j++; 
			else
			{
				if(i == n-1)  i = 0;	//���λ�������� 
				else	i++;
				if(j == 0)  j = n-1;	//���λ�������� 
				else	j--;
				if(a[j][i] != 0)		//�������������� 
				{	
					i = i0;
					j = j0;
					if(j == n-1)	j = 0;
					else	j++;
				}
			}
		}
	}
	
	if(n%4 == 0)
	{
		int temp;			//�м���� 
	    int k = 1;
		for(j=0; j<n; j++)
			for(i=0; i<n; i++)
				{
					a[j][i] = k;
					k++;
				}
		for(j=0; j<n/2; j++)
		{
			if(j%4 == 0 || j%4 == 3)
				for(i=0; i<n; i++)
					if(i%4 == 0 || i%4 == 3)
					{
						temp = a[j][i];
						a[j][i] = a[n-j-1][n-i-1];
						a[n-j-1][n-i-1] = temp;
					} 
			if(j%4 == 1 || j%4 == 2)
				for(i=0; i<n; i++)
					if(i%4 == 1 || i%4 == 2)
					{
						temp = a[j][i];
						a[j][i] = a[n-j-1][n-i-1];
						a[n-j-1][n-i-1] = temp;
					}
		}
	} 
	
	if(n%4 != 0 && n%2 == 0)
	{
		int m, k, t, temp;
		t = n/4;
		k = 1;
		m = n/2;
		
		i = m/2;
		j = 0;
		for(k; k<=m*m; k++)
		{
			a[j][i] = k;
			if(j==0 && i==m-1)
				j++; 
			else
			{
				if(i == m-1)
				i = 0;
				else
				i++;
				if(j == 0)
					j = m-1;
				else
					j--;
				if(a[j][i] != 0)
				{	
					if(i == 0)
						i = m-1;
					else
						i--;
					if(j == m-1)
						j = 0;
					else
						j++;
					if(j == m-1)
						j = 0;
					else
						j++;
				}
			}
		}
		
		i = m/2+m;
		j = m;
		for(k; k<=2*m*m; k++)
		{
			a[j][i] = k;
			if(j==m && i==n-1)
				j++; 
			else
			{
				if(i == n-1)
				i = m;
				else
				i++;
				if(j == m)
					j = n-1;
				else
					j--;
				if(a[j][i] != 0)
				{	
					if(i == m)
						i = n-1;
					else
						i--;
					if(j == n-1)
						j = m;
					else
						j++;
					if(j == n-1)
						j = m;
					else
						j++;
				}
			}
		}
		
		i = m/2+m;
		j = 0;
		for(k; k<=3*m*m; k++)
		{
			a[j][i] = k;
			if(j==0 && i==n-1)
				j++; 
			else
			{
				if(i == n-1)
				i = m;
				else
				i++;
				if(j == 0)
					j = m-1;
				else
					j--;
				if(a[j][i] != 0)
				{	
					if(i == m)
						i = n-1;
					else
						i--;
					if(j == m-1)
						j = 0;
					else
						j++;
					if(j == m-1)
						j = 0;
					else
						j++;
				}
			}
		}
		
		i = m/2;
		j = m;
		for(k; k<=4*m*m; k++)
		{
			a[j][i] = k;
			if(j==m && i==m-1)
				j++; 
			else
			{
				if(i == m-1)
				i = 0;
				else
				i++;
				if(j == m)
					j = n-1;
				else
					j--;
				if(a[j][i] != 0)
				{	
					if(i == 0)
						i = m-1;
					else
						i--;
					if(j == n-1)
						j = m;
					else
						j++;
					if(j == n-1)
						j = m;
					else
						j++;
				}
			}
		}
	
		for(i=0; i<t; i++)
			for(j=0; j<m; j++)
			{
				if(j == m/2)
				{
					temp = a[j][i+m/2];
					a[j][i+m/2] = a[j+m][i+m/2];
					a[j+m][i+m/2] = temp; 
				}
				else
				{
					temp = a[j][i];
					a[j][i] = a[j+m][i];
					a[j+m][i] = temp; 
				}
			}
	
		for(i=0; i<t-1; i++)
			for(j=0; j<m; j++)
			{
					temp = a[j][m/2+m-i];
					a[j][m/2+m-i] = a[j+m][m/2+m-i];
					a[j+m][m/2+m-i] = temp; 
			}	
	}
	
	
	for(j=0; j<n; j++)     //����÷� 
	{
		for(i=0; i<n; i++)
			printf("%-4d", a[j][i]);
		printf("\n");	
	}
	printf("\n��q���˳�");
	while(getchar() != 'q')
	;
}
