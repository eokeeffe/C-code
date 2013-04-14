/*Evan O'Keeffe
  10324289
  practical16 question1
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int max_integers(int param1,...)//dynamic amount of integers
{	
	int COUNT;
	int current;
	int max=0;
	va_list ap;//start the ap pointer
	va_start(ap,param1);//start the function arguement 
	for( COUNT=0; COUNT < param1 ; COUNT++)//now count until 
	{
		current=va_arg(ap,int);
		//printf("%d = current,max=%d\r\n",current,max);
		if(current>max){max=current;}//if the current value is greater than the max value then max = current
	}
	va_end(ap);
	
	return max;//returns the max number
}

int main()
{
	printf("%d is the answer\r\n",max_integers(7,3,7,10,30,25,21,15));
	return 0;
}