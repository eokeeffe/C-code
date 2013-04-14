/*Evan o'Keeffe
 10324289
 this is the guess game but with the modification of
 taking the correct word and writing it to a file*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SECRET "blue"

main()
{
	FILE *fopen(),*fp;
	char g[100],fn[100];
	int i=0,c;
	
	printf("please enter the filename that the program will write to\r\n");
	gets(fn);
	fp=fopen(fn,"w");
	
	if(fp==NULL){printf("that file doesn't exist\r\nor is the wrong one\r\n");}
	 
	 while(i<4)
	 {
		printf("please enter your guess\r\n");
		gets(g);
		
		if(strcmp( SECRET , g )==0 )
		{
			fprintf(fp,SECRET,g);
			printf("Correct guess, well done\n");
			return 0;
		}
		else
		{
			printf("Sorry %s is not the secret word\n");
			i++;
		}
		fclose(fp);
	  }
	printf("sorry but you have run out of tries please try again later\r\n");
	return 0;
}
	
	
	