/*Evan O'Keeffe
  10324289
  practical 15 question1
  the function f(s,t) will return the value where the letter in the 
  position in either string is not equal to the other 
*/
#include<stdio.h>
void parta(void);
void partb(void);
void partc(void);

int f(char *s, char *t);

int main()
{
	parta();
	printf("\n");
	partb();
	printf("\n");
	partc();
	printf("\n");
	return 0;
}
void parta()
{
	char *s,*t;
	char s1[]="abcd";
	char t1[]="babc";
	printf("Part A:\r\n");//part A
	printf("abcd=s\r\n");
	printf("babc=t\r\n");
	s=s1;
	t=t1;
	printf("%d is your answer\r\n",(f(s,t)));
}

void partb()
{
	char *s,*t;
	char s1[]="abcd";
	char t1[]="bcd";
	printf("Part B:\r\n");//Part B
	printf("abcd=s\r\n");
	printf("bcd=t\r\n");
	s=s1;
	t=t1;
	printf("%d is your answer\r\n",(f(s,t)));
}


void partc()
{
	char *s,*t;
	char s1[]="nave";
	char t1[]="evanokeeffe";
	printf("Part C:\r\n");//Part C
	printf("string 1=nave\r\n");
	printf("string 2=naveevan\r\n");
	s=s1;
	t=t1;
	printf("%d is your answer\r\n",(f(s,t)));
}

int f(char *s, char *t)
{
	char *p1, *p2;
	for ( p1 = s; *p1; p1++) 
	{
		for (p2 = t; *p2; p2++)
		if (*p1 == *p2) break;
		if (*p2 == '\0') break;
		
	}	
	return p1 - s;
}