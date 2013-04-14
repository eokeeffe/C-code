#include<stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]);
void itoa(int n,char s[],int min_width);

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n,char s[],int min_width)
{
	int i,sign;
	
	if ((sign=n) < 0)/*record sign*/
	{
		n = -n;
	}
	i=0;
	
	do
	{	//generate digits in reverse order
		s[i++] = n % 10 + '0';	//get next digit
	}
	while( (n /= 10) > 0);	//delete it
	if (sign < 0)
	{
		s[i++] = '-';
	}
	
	while(i < min_width)
	{
		s[i++] = ' ';
	}
	
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char string[] = "abc";
	
	printf("%s\r\n",string);
	
	itoa(5,string,strlen(string));
	
	printf("%s\r\n",string);
	
	return 0;
}