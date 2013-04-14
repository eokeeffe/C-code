/*evan o'keeffe
   10324289
   practical 11 question6
*/
#include<stdio.h>

void to_binary(int value);//take the integer and print the binary equivalent

int main()
{
	int value;
	printf("please enter a value to be converted to a bin output\r\n");
	scanf("%d",&value);
	to_binary(value);
	return 0;
}
void to_binary(int value)
{
	int divisor;
	int array[100];
	int i=0,a,b,c;
	
	while(i<100){array[i]='\0';i++;}//clean the array
	i=0;
	
	divisor=value/2;//remove the first zero by dividing before the while loop
	while(divisor>0)//stop when the divisor is at 0
	{
		if((divisor%2)==0){array[i]=0;}//to convert dec to bin , divide by 2 each time and 
		else if((divisor%2)!=0){array[i]=1;}//if the remainder is o place in the array
											//or if 2 doesn't divide evenly place 1 in the array
		printf("divisor=%d\r\n",divisor);
		divisor = divisor/2;//divide by 2 each round to lower the divisor
		i++;
	}
	printf("i=%d\r\n",i);		//debug routine
	printf("number:%d= to binary 0b\r\n",value);//print the number in binary format starting with 0b
	a=0;
	while(a<=i)//print all numbers in the array backwards
	{
		printf("%d\t",array[a]);
		a++;
	}
}