/*
	Tier 1 : Part 5	:	Question 9
	
	You may have seen in the previous example that strlen was used
	This one however is a custom strlen function that they will make
	
	This is the bridge question to the next tutorial where control flow is 
	done
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char string[20] , dummy;
    int loop_count=0 ,control_statement = 20 ;
	int zero = 0 , string_length =0, clean;
   
   //clean the array first
   for(clean=0;clean<control_statement;clean++){string[clean]='\0';}
   
    printf("Please enter something for string 1\r\n");
	scanf("%s",&string);
	dummy=getchar();
	
	for( loop_count = 0 ; loop_count < control_statement ; loop_count++)
	{
		if(string[loop_count]>='a'&&string[loop_count]<='z') // conditional statement that will only count the lower case characters
		{													 //explained more in the next section
			string_length++;
		}
	}
	
	printf("In the string %s and the string length is %d\r\n",string,string_length);
	
	return 0;
}