/*Evan O'keeffe
  10324289
  practical17 question3
  comments below
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i,j,k;
int user_choice;

int print_table(int user_choice , int array[][user_choice])
{
	int lenght[user_choice];
	int row[user_choice];
	int temp0,temp1;
	
	for(i=0,j=0;i<user_choice;i++)//calculate row summations + print out the table
	{
		temp1=0;
		printf("Row%d\t",i);
		for(j=0;j<user_choice;j++)
		{
			temp0=0;
			temp0=array[i][j];
			temp1 += temp0;//accumulate the horizontal numbers
			printf("%d ",array[i][j]);
		}
		row[i]=temp1;//place the sum of the horizontal numbers in the row array
		printf("\n");
	}
	for(i=0,j=0;j<user_choice;j++)//get lenght summations
	{
		//printf("i=%d and j=%d\r\n",i,j);
		temp1=0;
		for(i=0;i<user_choice;i++)
		{
			temp0=0;
			temp0 = array[i][j];
			temp1 += temp0;//accumulate the vertical sum of the array
		}
		lenght[j]=temp1;//place the vertical sum in the lenght array
		//printf("len%d=%d\n",j,lenght[j]);
	}
	printf("\nrow sumations  ");
	for(i=0;i<user_choice;i++){printf("%d ",row[i]);}
	printf("\n");
	printf("\nlenght sumations  ");
	for(i=0;i<user_choice;i++){printf("%d ",lenght[i]);}
	printf("\n");
	
	return 0;
}

int main()
{
	int random;
	srand(time(NULL));//seed the random number generator
	printf("Please enter the array height/row\r\n");
	scanf("%d%*c",&user_choice);
	
	int array[user_choice][user_choice];//create array to users specification
	
	for(i=0;i<user_choice;i++)
	{
		for(j=0;j<user_choice;j++)
		{
			array[i][j]=rand();//fill the array with random numbers
			//printf("%d ",array[i][j]);
		}
		//printf("\n");
	}
	
	print_table(user_choice, array );//pass the array and user number to the print table function
	
	return 0;
}