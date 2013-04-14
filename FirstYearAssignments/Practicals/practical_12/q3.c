/*Evan O'Keeffe
  10324289
  practical 12 question 3
*/
#include<stdio.h>
#include<string.h>

#define TOUPPER(c) \
('a'<=(c) && (c)<='z' ? (c)-'a'+'A' : (c) )

int main()
{
	char s[10];
	
	printf("Part A\r\n");
	strcpy(s,"abcd");
	int i=0;
	putchar(TOUPPER(s[++i]));
	
	printf("\nPart B\r\n");
	strcpy(s,"0123");
	i=0;
	putchar(TOUPPER(s[++i]));
	
	return 0;
}