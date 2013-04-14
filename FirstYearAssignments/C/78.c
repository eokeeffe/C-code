/*Evan O'Keeffe
  10324289
  my echo program */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
main(int argc, char *argv[])
{
	int i;
	printf("Number of arguements: %d  \r\n",argc);
	for(i=0;i<argc;i++)
	printf("Arguement number %d is : %s  \n",i,argv[i]);
}