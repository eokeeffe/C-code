/*Evan O'Keeffe
  10324289
  question 8 practical 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int digit(char array[100],int point);

void main()
{
	char array[100];
	int user_input;
	int a;
	int point;
	while(a<100){array[a]='\0';a++;}
	
	printf("Please enter your numbers here please\r\n");
	gets(array);
	printf("Please enter the number your looking for \r\n");
	scanf("%d",&user_input);
	a=0;
	int n=0;
	
	while(a<100)
	{
		if(array[a]=='1'||array[a]=='2'||array[a]=='3'||array[a]=='4'||array[a]=='5'||array[a]=='6'
		||array[a]=='7'||array[a]=='8'||array[a]=='9'||array[a]=='0'){n++;}
		a++;
	}
	//printf("There are %d elements in the array\r\n",n);
	//printf("A=%d\r\n",a);
	point=n-user_input;
	//printf("%d is the point \r\n",point);
	printf("\n%c is your number\r\n",toascii(digit(array,point)));//as i use a char array 
																  //i must convert the integer from the decimal value back to ascii value
}
int digit(char array[100],int point)
{
	return (array[point]);
}
	