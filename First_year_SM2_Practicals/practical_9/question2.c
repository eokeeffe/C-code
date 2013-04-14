/*Evan O'Keeffe
  10324289
  practical9 question2
*/
#include<stdio.h>

void main()
{
	char text[80];
	char dummy;
	int i;
	
	for(i=0;i<60;i++)
	{
		printf("Please enter for character number %d\r\n",i);
		text[i]=getchar();
		dummy=getchar();
	}
	
	for(i=0;i<60;i++)
	{
		printf("for character number: %d\r\n",i);
		printf("\n");
		putchar(text[i]);
		printf("\n");
	}
	
}