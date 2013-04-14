/*Evan O'Keeffe
  10324289
  question 1 practical 3 */
  
#include<stdio.h>

void main()
{
	int i=1;
	int chosen;
	
	do
	{
		printf("Please enter the number\r\n");
		scanf("%d",&chosen);
		if(chosen>0)
		{
			printf("%d\n",i);
			i++;
		}
	}
	while(i<11);
}