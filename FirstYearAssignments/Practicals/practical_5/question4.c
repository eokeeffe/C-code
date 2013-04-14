/*Evan O'Keeffe
  10324289
  practical 5 question4
*/
#include<stdio.h>


void main()
{
	int matrix1[3][4];
	int matrix2[3][4];
	int result[3][4];
	int a=0,b=0;
	
	while(a<12)
	{
		while(b<12)
		{
			printf("please enter a value for slot %d of matrix 1\r\n",b);
			scanf("%d",&matrix1[a][b]);
			printf("please enter a value for slot %d of matrix 2\r\n",b);
			scanf("%d",&matrix2[a][b]);
			b++;
		}
	 a++;
	}
	
	a=0;
	b=0;
	while(a<12)
	{
		while(b<12)
		{
			result[a][b]=matrix1[a][b]+matrix2[a][b];
			printf("%d\t",result[a][b]);
			b++;
		}
	 a++;
	}
}