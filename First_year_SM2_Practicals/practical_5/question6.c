/*Evan O'Keeffe
  10324289
  practical 5 question6
*/
#include<stdio.h>

int a,b;
void symmetry(int matrix[a][b],int a,int b,int count);

void main()
{
	
	int count=0,values=0;
	int number;
	
	printf("Please enter the value for the rows of the matrix\r\n");
	scanf("%d",&a);
	printf("Please enter the column value for the matrix\r\n");
	scanf("%d",&b);
	
	int matrix[a][b];
	
	printf("How many actual values do you want in the matrix\r\n");
	scanf("%d",&number);
	
	while(count<number)
	{
		printf("number %d for the matrix\r\n",count);
		scanf("%d",&matrix[count][values]);
		count++;
	}
	symmetry(matrix,a,b,count);
}
void symmetry(int matrix[a][b],int a,int b,int count)
{
	int c=0,d=0,e=0;
	
	if(matrix[a][b]!=matrix[b][a]){printf("first symmetry test failed as the rows and columns are different\r\n");}
	else
	{
		while(c<count)
		{
			if(matrix[d][c]==matrix[c][d]){/*printf("This is symmetric so far\r\n");*/e++;}
			d++;
			c++;
		}
		printf("%d/%d the same\r\n",e,c);
	}
}