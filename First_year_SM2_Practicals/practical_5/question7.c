/*Evan O'Keeffe
  10324289
  practical 5 question7
  sadly the code seems to only work with matrixes that are properly defined 
  for multiplication
*/
#include<stdio.h>

int a,b,c;
void MM(int A[a][b],int B[c],int number);

void main()
{	
	int count=0,values=0;
	int number,vector;
	int c,vector_values=0;
	printf("Please enter the value for the rows of the matrix\r\n");
	scanf("%d",&a);
	printf("Please enter the column value for the matrix\r\n");
	scanf("%d",&b);
	printf("Please enter the value for the vector \r\n");
	scanf("%d",&c);
	printf("How many actual values do you want in the matrix\r\n");
	scanf("%d",&number);
	printf("How many actual values do you want in the vector\r\n");
	scanf("%d",&vector);
	
	
	int A[a][b];
	int B[c];
	if(c<vector){printf("Error with the vector values\r\n");}
	else
	{
		while(count<number)
		{
			printf("number %d for the matrix\r\n",count);
			scanf("%d",&A[count][values]);
			count++;
			values++;
		}
		
		count=0;
		
		while(count<vector)
		{
			printf("Please enter value %d for the vector\r\n",count);
			scanf("%d",&B[vector_values]);
			count++;
			vector_values++;
		}
		
		
		
		MM(A,B,number);
	}
}
void MM(int A[a][b],int B[c],int number)
{
	int result[a][b];
	
	int c=0;
	int d=1;
	while(c<number)
	{
		result[c][d]=A[c][d]*B[c];
		c++;
		d++;
	}
	c=0;
	d=0;
	while(c<number)
	{
		printf("%d\t",result[c][d]);
		c++;
		d++;
	}
}