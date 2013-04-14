/*evan o'keeffe
  10324289     */
  /*Read a string of text and to display the number of occurences of the a charatcer*/
  
#include<stdio.h>

main(void)
{
	char text[10];
	int sum,i,count;
	
	printf("this program needs text\r\n ,please enter some\r\n");
	gets(text);
	/*printf("you have enter %s\r\n",text);*/
	
	i=count=0;
	sum=0;

	if(text[i]<' '){printf("there was no characters\r\n");}
	{
	   while(text[i]!= '\0')
	 { if(text[i]=='a'){
	   count=count+1;
	   printf("there was characters\r\n");}
		{
		
		i=i+1;
		/*printf("there no characters\r\n");*/
		}
	 }
	}
	 printf("the letter a appears %d times in the string %s\r\n",count,text);
	 
	 return 0;
}
  