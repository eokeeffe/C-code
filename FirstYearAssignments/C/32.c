/*Evan o'keeffe 10324289
	08/10/2010
	this program will read six salaries and displays them
	and the difference from the average they are*/
	
	float salary1,salary2,salary3,salary4;
	float salary5,salary6,average,difference;
	float numbers;
	char right;
	int i;
#include<stdio.h>
main()
{	 
	printf("please enter salary1\r\n");
	scanf("%f",&salary1);
	printf("please enter salary2\r\n");
	scanf("%f",&salary2);
	printf("please enter salary3\r\n");
	scanf("%f",&salary3);
	printf("please enter salary4\r\n");
	scanf("%f",&salary4);
	printf("please enter salary5\r\n");
	scanf("%f",&salary5);
	printf("please enter salary6\r\n");
	scanf("%f",&salary6);
	
	average=((salary1+salary2+salary3+salary4+salary5+salary6)/2);
	/*printf("The salaries below are what was entered\r\n");
	printf("%f\r\n",salary1);
	printf("%f\r\n",salary2);
	printf("%f\r\n",salary3);
	printf("%f\r\n",salary4);
	printf("%f\r\n",salary5);
	printf("%f\r\n",salary6);*/
	printf("is this right?\r\n,please enter n for no and y for yes");
	right=getchar();
	if(right=='y'){int i;
				   i=0;
				   while(i<10){
				   difference=numbers[i]-average;
				   printf("Deviation from mean %f %f \n", difference, numbers[i]);
							}
	if else(right=='n'){printf("please start again\r\n");
	
}
	