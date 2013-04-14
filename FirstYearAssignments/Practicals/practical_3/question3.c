/*Evan O'Keeffe
  10324289
  question 3 practical 3 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void wait_for_user();
void adding(int number1,int number2);
void subtracting(int number1,int number2);
void dividing(int number1,int number2);
void multiplying(int number1,int number2);

void main()
{
	char user_choice;
	int number1,number2;
	
	printf("Please enter the numbers you are using\r\n");
	scanf("%d%d",&number1,&number2);
	printf("Are you adding= character a\r\n");
	printf("Are you subtracting= character s\r\n");
	printf("Are you dividing= character d\r\n");
	printf("Are you multiplying= character m\r\n");
	wait_for_user();
	
	scanf("%c",&user_choice);
	
	if(user_choice=='a'){adding(number1,number2);}
	if(user_choice=='s'){subtracting(number1,number2);}
	if(user_choice=='d'){if(number2==0){printf("denimnator is 0 which is illegal\r\n");}else dividing(number1,number2);}
	if(user_choice=='m'){multiplying(number1,number2);}
}
void adding(int number1,int number2)
{
	int answer;
	answer=number1+number2;
	printf("Your answer is %d\r\n",answer);
}
void subtracting(int number1,int number2)
{
	int answer;
	answer=number1-number2;
	printf("Your answer is %d\r\n",answer);
}
void dividing(int number1,int number2)
{
	int answer;
	answer=number1/number2;
	printf("Your answer is %d\r\n",answer);
}
void multiplying(int number1,int number2)
{
	int answer;
	answer=number1*number2;
	printf("Your answer is %d\r\n",answer);
}
void wait_for_user()
{
	char dummy[100];
	printf("Press enter\r\n");
	gets(dummy);
}