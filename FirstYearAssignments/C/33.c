/*Evan o'keeffe 10324289
	08/10/2010
	this program will read choice number of salaries and displays them
	and the difference from the average they are*/
#include<stdio.h>
float main()
{
	float numbers[100] ; 
	float sum, average,diff;
	int i,c;
	i=0;
	sum=0;
	
	printf("Please enter the number of salaries here\r\n");
	scanf("%d",&c);
	while(i<c) 
	{ 
	 printf("please enter the value here\r\n");
	 scanf("%f",&numbers[i]);
	 sum = sum+numbers[i]; 
	 i=i+1;
	} 
	
	average = sum/c; 
	i=0;
	
	while(i<c)
	{
	diff=average-numbers[i];
	if(diff<=0){diff=diff*(-1);}
	i=i+1;
	printf("the deviation is %f \r\n",diff);
	}
	
	printf ("Average = %f \n", average);
}

