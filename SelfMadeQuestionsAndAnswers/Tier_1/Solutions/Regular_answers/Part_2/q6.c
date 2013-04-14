/*
	Tier 1 : Part 2	:	Question 6
*/
#include<stdio.h>

int main()
{
	int length , width , height , volume_of_a_rectangle;
	
	printf("Please enter a lenght \r\n");
	scanf("%d",& length);
	
	printf("Please enter a width \r\n");
	scanf("%d",& width);
	
	printf("Please enter a height \r\n");
	scanf("%d",& height);
	
	volume_of_a_rectangle = length * width * height;
	
	printf("The volume of the rectangle is %d \r\n",volume_of_a_rectangle);
	
	return 0;
}