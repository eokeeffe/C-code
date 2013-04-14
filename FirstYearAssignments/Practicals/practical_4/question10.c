/*Evan O'Keeffe
  10324289
  question 10 practical 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int times_tables(int user_input);

void main()
{
	int user_input;
	printf("Please enter your digit here please :\n");
	scanf("%d",&user_input);
	if(user_input<=10)
		{times_tables(user_input);}
	else
	{printf("please try again\r\n");}
}
int times_tables(int user_input)
{
	int a,b,c;
	for(a=1;a<=user_input;a++)
		{
			
			for(b=1;b<=user_input;b++)
			{
				c=(pow(a,b));
				printf("%d\t",c);
			}
			printf("\n");
			b=1;
		}
}