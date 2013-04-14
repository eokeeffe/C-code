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
	if( c == 'a')
	{
		return 'A';
	}
	else if( c == 'b')
	{
		return 'B';
	}
	else
	{
		return 'X';
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