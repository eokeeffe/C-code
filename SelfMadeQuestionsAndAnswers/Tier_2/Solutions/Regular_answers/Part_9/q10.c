/*
	Tier 2 : Part 9	:	Question 10
	
*/
#include<stdio.h>

int main()
{
	int matrix_one[3][3] , matrix_two[3][3] , added_matrix[3][3];
	int x_coordinate , y_coordinate ;
	
	printf("please enter the 9 numbers for the first matrix\r\n");
	
	for(x_coordinate = 0 , y_coordinate = 0 ; x_coordinate < 3 ; x_coordinate++)
	{
		y_coordinate = 0;
		for(y_coordinate = 0 ; y_coordinate < 3 ; y_coordinate++)
		{
			while(scanf("%d",&matrix_one[x_coordinate][y_coordinate])!=1)
			{fflush(stdin);}
		}
	}
	
	printf("please enter the 9 numbers for the second matrix\r\n");
	
	for(x_coordinate = 0 , y_coordinate = 0 ; x_coordinate < 3 ; x_coordinate++)
	{
		y_coordinate = 0;
		for(y_coordinate = 0 ; y_coordinate < 3 ; y_coordinate++)
		{
			while(scanf("%d",&matrix_two[x_coordinate][y_coordinate])!=1)
			{fflush(stdin);}
		}
	}
	
	
	for(x_coordinate = 0 , y_coordinate = 0 ; x_coordinate < 3 ; x_coordinate++)
	{
		y_coordinate = 0;
		for(y_coordinate = 0 ; y_coordinate < 3 ; y_coordinate++)
		{
			added_matrix[x_coordinate][y_coordinate]= matrix_one[x_coordinate][y_coordinate] + matrix_two[x_coordinate][y_coordinate];
		}
	}
	
	for(x_coordinate = 0 , y_coordinate = 0 ; x_coordinate < 3 ; x_coordinate++)
	{
		y_coordinate = 0;
		for(y_coordinate = 0 ; y_coordinate < 3 ; y_coordinate++)
		{
			added_matrix[x_coordinate][y_coordinate]= matrix_one[x_coordinate][y_coordinate] + matrix_two[x_coordinate][y_coordinate];
		}
	}
	
	printf("\r\n");
	
	for(x_coordinate = 0 , y_coordinate = 0 ; x_coordinate < 3 ; x_coordinate++)
	{
		y_coordinate = 0;
		for(y_coordinate = 0 ; y_coordinate < 3 ; y_coordinate++)
		{
			//printf("%d \t+ %d \t= %d",matrix_one[x_coordinate][y_coordinate],matrix_two[x_coordinate][y_coordinate],added_matrix[x_coordinate][y_coordinate]);
			printf("%d ",added_matrix[x_coordinate][y_coordinate]);
		}
		printf("\r\n");
	}
	
	
	
	
	return 0;
}