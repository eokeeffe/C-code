/*Evan O'Keeffe
  10324289
  reads a string then displays the number of uppercase/lowercase characters its has */
  /*also reads and prints the position of said characters, ying huang helped on this program*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{ 
	char c[100];
	int i=0;

	printf("please enter the word\r\n,no numbers please\r\n");
	gets(c);
	int counter=0;
				  
	 while(c[i] != '\0')
	 {
		if(c[i]>='A' && c[i] <='Z')
		{
			counter++;
		}
		else if(c[i] >= 'a' && c[i] <= 'z')
		{
			counter++;
		}
		i = i+1;
	}
	printf("count char:%d",counter);
	
	
}