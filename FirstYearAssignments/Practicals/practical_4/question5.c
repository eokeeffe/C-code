/*Evan O'Keeffe
  10324289
  question5 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int powerof(unsigned int user_number,unsigned int a);
unsigned int answer;
void main()
{	
	unsigned int user_number;
	unsigned int a;
	unsigned int ans;
	
	printf("Please enter your number here\r\n");
	scanf("%d",&user_number);
	printf("how big do you want the power to be?\r\n");
	scanf("%d",&a);
	ans = powerof(user_number,a);
	printf("\n %d to the power of %d = %d\r\n",user_number,a,ans);

}
unsigned int powerof(unsigned int user_number,unsigned int a)
{	
	if(a<=0){return 1;}
	else
	{ 
		answer=user_number*powerof(user_number,a-1);
		return answer;
	}
}
