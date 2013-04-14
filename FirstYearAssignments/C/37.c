/*Evan O'Keeffe
  10324289
  this program takes a number of arrays and prints them in a formated output*/

#include<stdio.h>
main()
{
	char name[100],add1[100],add2[100],add3[100];
    printf("Please enter your name\r\n");
	gets(name);
    printf("please enter address line 1\r\n");
	gets(add1);
	printf("Please enter Address line 2\r\n");
	gets(add2);
	printf("Please enter Address line 3\r\n");
	gets(add3);
	
    printf("%s\r\n",name);
	printf(" %s\r\n",add1);
	printf("  %s\r\n",add2);
	printf("   %s\r\n",add3);
	
	printf("Thank You For Using This\r\n");
	return 0;
}