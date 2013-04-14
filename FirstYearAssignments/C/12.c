/*evan o'keeffe 10324289
	24/09/2010
	this program takes the input colour and then places this with the words in the printf function*/
#include<stdio.h>

int main()
{	
	char colour1[10];/*I made the number of possible characters small for ease of understanding*/
					 /*I entered a 12 character colour and the program crashed, i then changed the character limit to 
					   20 and the program worked for the 12 char colour*/
	
	printf("enter favourite colour here\r\n");/* \r is used for placing an extra space after the printf for clarity*/
	gets(colour1);
	
	printf("Yuk I Hate %s\n\r",colour1);
	printf("You are the weakest link good bye\a");/*tested the \a Bell function to see if it worked, it worked very well*/
	return 0;
}
	
	