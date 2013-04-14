/*Evan O'Keeffe
  10324289
  reads a string then displays the position of the character its looking for */

#include<stdio.h>

main()
{ 
	char text[20];
	int i,sum,no;
	no =1;
	i=0;
	
	printf("please enter your word\r\n");
	gets(text);

	if(text[i]<' '){printf("there was no characters\r\n");}
	{
	 while(text[i]!= '\0')
	{ if(text[i]=='a')
	    {
	   printf("the charater a appears in position %d of the\r\n",i+1);
	   no=2;
	   break;
	    }
		i=i+1;
		
	}
	if(no==1)
		{
		printf("there was no a's in the string %s\r\n",text);
	    }
	 printf("the a character appears in the string %s\r\n",text);
	 
	 return 0;
    }
}
   