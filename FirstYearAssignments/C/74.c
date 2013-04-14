/*Evan O'Keeffe
  10324289
  fatal error function*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void fatal(char msg[]);
main()
{	
	char msg [200];
	printf("please enter anything\r\n");
	gets(msg);
	fatal(msg);
}
void fatal(char msg[])
{
	printf("%s\r\n\a",msg);
	exit(1);
}
