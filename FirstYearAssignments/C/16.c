/* Evan O'Keeffe
   10324289 
   program to find the volume of a box*/
#include <stdio.h>

void main()

{
	int height=10;
	int width=12;
	int depth=8;
	int n=0;
	char c=0;
	while(n++ < 10)
	{
	printf("the answer is %d\r\n",height*width*depth);
	}
	while(1)
	{
	c=getch();
	if(c=='e')break;
	}
}