/*Evan O'keeffe
  10324289
  practical17 question4
  comments below
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i,j,k;
int snum,qnum;

int print_table(int snum,int qnum,int array[snum][qnum])
{
	int max,min;
	float avg;
	max=0;
	min=0;
	avg=0.0;
	/* this function is a debug routine I left in for seeing if the table was being drawn right
	for(i=0;i<snum;i++)
	{
		for(j=0;j<qnum;j++){printf("i=%d , j=%d\r\n",i,j);}
		printf("\n");
	}
	*/
	for(i=0;i<snum;i++)
	{
		if(i==0){min=array[i][j];}//set the initial value to the first element in the array
		printf("Student:%d  ",i);
		for(j=0;j<qnum;j++)
		{
			printf("| %d | ",array[i][j]);//print the table of scores
			
			if(array[i][j]>max)
			{
				max=array[i][j];//find the max value
				//printf("max=%d\r\n",max);
			}
			if(array[i][j]<min)
			{
				min=array[i][j];//find the min value
				//printf("min=%d\r\n",min);
			}
			
			avg += array[i][j];//accumulate all scores over the loop
			//printf("avg=%d\r\n",avg);
			
		}
		printf("\n");
	}
	printf("lowest score was %d\r\n",min);
	printf("Highest score was %d\r\n",max);
	printf("Average score was %f\r\n",(float)(avg/snum/qnum));//so sum of all scores/number of students/number of quizzes = avg overall
															  //,taking equal weighting, also value has to be a float , so its converted to one 
	
	return 0;
}

int main()
{
	int random;
	srand(time(NULL));//seed the random number generator
	printf("Please enter the number of students\r\n");
	scanf("%d%*c",&snum);
	printf("Please enter the number of quizzes\r\n");
	scanf("%d%*c",&qnum);
	
	int array[snum][qnum];//create array to users specification
	
	for(i=0;i<snum;i++)
	{
		for(j=0;j<qnum;j++)
		{
			array[i][j]=rand()%100;//fill the array with random numbers that will represent grades between 0 and 100,for simplicity
			//printf("%d ",array[i][j]);
		}
		//printf("\n");
	}
	
	print_table(snum,qnum,array);//pass the snum,qnum and array to print table
	return 0;
}