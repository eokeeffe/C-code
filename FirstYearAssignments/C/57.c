/*Evan o'Keeffe
 10324289
 this is the guess game but with the modification of
 taking multiple words and from a file  */
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>

main()
{
	FILE *fopen(),*fp;
	char g[100],fn[100];
	int i=0,a=0,b=0,c,d,e;
	char secret[80];
	
	printf("please enter the filename that the program will read to\r\n");
	gets(fn);
	fp=fopen(fn,"r");
	
	
	if(fp==NULL){printf("that file doesn't exist\r\nor is the wrong one\r\n");}
	 
	 
	 while(a<strlen(secret))
	 {
		b=0;
		while(b<80){secret[b++]!='\0';}
		fgets(secret,80,fp);
		/*printf("%s",secret);*/ 	/*debug*/
		
		b=0;
		while(b<100){g[b++]='\0';}	/*clearing the buffer*/
		
		printf("please enter your guess\r\n\n");
		gets(g);
		
		/*printf("secret=%d g = %d\r\n",strlen(secret),strlen(g));*/	/*this is a debug feature*/
		secret[strlen(secret)-1]='\0';
		
		/*b=0;					/*debug feature*/
		/*while(g[b]!='\n'&&b<100)
		{
		b++;
		}*/
		/*g[b]='\0';
		g[b+1]='\0';*/
		
		if(strcmp(g , secret )==0)
		{
			printf("Correct guess, well done\n\n");
		}
		else
		{
			printf("Sorry %s is not the secret word\n\n",g);
		}
		a++;
	  }
	  fclose(fp);
	printf("sorry but you have run out of tries please try again later\r\n\n");
	return 0;
}