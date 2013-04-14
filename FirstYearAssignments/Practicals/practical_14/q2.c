/* Evan O'Keeffe
   10324289
   practical 14 question2
*/
#include<stdio.h>

int f(int i)
{
	static int j = 0;
	return i * j ++;//return i*j=i*j+1
}

int main()
{
	printf("first call answer= %d \r\n",f(10));//should be 0 as i*0=0
	
	int count=0;
	
	while(count<5)
	{
		printf("%d call answer= %d \r\n",count,f(10));//j=0,j=1,j=2,j=3,j=4 * 10 , output = 0,10,20,30,40
		count++;
	}
	return 0;
}