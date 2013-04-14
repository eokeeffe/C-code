/*Evan O'Keeffe
  10324289
  practical 5 question3
*/
#include<stdio.h>

void main()
{
	int scores[6][3];
	int a=0,b=0,c;
	
	while(a<6)
	{
		
		while(b<3)
		{
			printf("What was student %d's score?\r\n",a);
			scanf("%d",&scores[a][b]);
			//printf("problem here\r\n");
			b++;
		}
		a++;
		b=0;
	}
	a=0;
	while(a<6)
	{
		while(b<3)
		{
			printf("Student#=%d,Mark=%d\r\n",a+1,scores[a][b]);
			printf("\n");
			b++;
		}
		a++;
		b=0;
	}
}