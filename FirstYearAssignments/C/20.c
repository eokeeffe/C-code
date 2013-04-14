/*just messing wwith some code*/

#include<stdio.h>

int main()
{
	char name[20];
	float age;
	
	printf("please enter your name\r\n");
	gets(name);
	
	printf("please enter age\r\n");
	scanf("%f",&age);
	
	if (age>=18)
	{printf("your just right\r\n\a");
	}
	if (age<18)
	{printf("sorry cant do that\r\n");
	}
	
	
	printf("thank you\r\n");
	
	return 0;
}
	