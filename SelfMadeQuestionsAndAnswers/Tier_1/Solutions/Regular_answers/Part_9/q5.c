/*
	Tier 1 : Part 9	:	Question 5
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float calculator(char* control_string,int number_1,int number_2,int number_3,int number_4);

int main()
{
	char control_string[50];
	int number_1,number_2,number_3,number_4;
	
	printf("Please enter whether you want to add,subtract,divide or mulitply\r\n");
	scanf("%s",&control_string);
	
	printf("Please enter first number \r\n");
	scanf("%d",&number_1);
	
	printf("Please enter second number \r\n");
	scanf("%d",&number_2);
	
	printf("Please enter third number \r\n");
	scanf("%d",&number_3);
	
	printf("Please enter fourth number \r\n");
	scanf("%d",&number_4);
	
	printf("%lf is the answer\r\n",calculator(control_string,number_1,number_2,number_3,number_4));
	return 0;
}

float calculator(char* control_string,int number_1,int number_2,int number_3,int number_4)
{
	float answer;
	if(strcmp(control_string,"add")==0)
	{
		answer=number_1+number_2+number_3+number_4;
		return answer;
	}
	if(strcmp(control_string,"subtract")==0)
	{
		answer=number_1-number_2-number_3-number_4;
		return answer;
	}
	if(strcmp(control_string,"divide")==0)
	{
		answer=number_1/number_2/number_3/number_4;
		return answer;
	}
	if(strcmp(control_string,"multiply")==0)
	{
		answer=number_1*number_2*number_3*number_4;
		return answer;
	}
	else
	{
		printf("String wasn't add,subtract,divide or mulitply \r\n");
		printf("Please try again \r\n");
		exit(0);
	}
}