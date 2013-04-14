/*Evan O'Keeffe
  10324289
  practical16 question2
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int display(int param1,... )
{
	int COUNT=0;
	
	va_list ap;//start the ap pointer
	
	va_start(ap,param1);//start the function arguement 
	
	for( COUNT=0; COUNT < param1 ; COUNT++)//now count until 
	{
		printf("%s ",va_arg(ap,char*));
	}
	va_end(ap);
	
	return 0;
}

int main()
{
	display(5,"I","AM","BATMAN","NOT","ROBIN");
	return 0;
}