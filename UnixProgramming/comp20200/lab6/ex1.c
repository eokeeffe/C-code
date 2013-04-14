#include<stdio.h>
#include<string.h>
int strrindex(char s[],char t);

int main()
{
	char a[]= "Hello World and Hello Universe";
	char t;
	printf("Enter a character\r\n");
	scanf("%c%*c",&t);
	printf("the letter %c occurs at the right most index %d\r\n",t,strrindex(a,t));
	printf("in the string %s\r\n",a);
	return 0;
}

int strrindex(char s[],char t)
{
	int index=-1,i;
	for(i=0;i < strlen(s) ; i++)
	{
		if( s[i] == t)
		{
			index = i;
		}
	}
	return index;
}
