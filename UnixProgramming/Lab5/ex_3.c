#include <stdlib.h>
#include <stdio.h>

char transform(char c)
{
	/*
	Transform: 
	'a' => 'A'
	'b' => 'B'
	any other character => 'X'
	*/
	switch(c)
	{
		case 'a':
		{
			return 'A';
		}
		case 'b':
		{
			return 'B';
		}
		default:
		{
			return 'X';
		}
	}
	return c;
}

int main ()
{
	char c;
	while ((c=getchar())!=EOF)
	{
		printf("%c",transform(c));
	}
	return 0;
}