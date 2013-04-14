/*Evan o'keeffe 10324289
	22/09/2010
	this program takes the three defined integers
	and the multiplies them to get the volume of the rectangle*/
#include <stdio.h>

void main()

{
	int height=10;
	int width=12;
	int depth=8;
	int n=0;/*this was added after the prgram did the volume,this allows the program to loop so that I could turn on the program outside the cmd*/
	char c=0;/*this was added after the loop function worked,I played around with using the getch function so that the program terminates when i press 'e'*/
	while(n++ < 10)
	{
	cout("the answer is %d\r\n",height*width*depth);/*the cout function here was to prove to the person beside me that it was the same as using printf*/
	}
	while(1)
	{
	c=getch();
	if(c=='e')break;
	}
}