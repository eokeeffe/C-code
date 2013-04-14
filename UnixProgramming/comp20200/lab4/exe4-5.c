#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXNUM 20    /* maximum input number length */

int htoi(char s[]);
int ishex(char C);
int checkline(char s[],int i);

int main()
{
	int c, i;
	char hexin[MAXNUM];

	for (i=0; i < MAXNUM-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	{
		hexin[i] = c;
		//printf("%x:%c\r\n",c,c);
	}
	hexin[i] = '\0';
	
	int answer;
	answer = htoi(hexin);

	printf("hex = %X\r\n",answer);
	printf("decimal number = %d\r\n",answer);

	return 0;
}

int ishex(char C)
{
	if(((C >= '0') && (C <= '9'))
	 ||
	 ((C >='A') && (C <= 'F'))
	 ||
	 ((C >= 'a') && (C <= 'f')))
	{
		return 1;
	}
	return 0;
}

int checkline(char s[],int i)
{
	for(i=i;i<strlen(s);i++)
	{
		if(isxdigit(s[i]))
		{
			continue;
		}
		if(!(isxdigit(s[i])))
		{
			return (-1);
		}
	}
	return 1;
}

int htoi(char s[])
{
	int answer;
	int i=0;
	if(s[i]=='0')
        {
                i++;
                if(s[i]=='x'||s[i]=='X')
                {i++;}
        }
	if(checkline(s,i) != 1 )
	{
		return (-1);
	}
	for(answer=0;ishex(s[i])/*isxdigit(s[i])*/;i++)
	{
		if(isdigit(s[i])){answer = 16 * answer + (s[i]-'0');}
		if(isupper(s[i])){answer = 16 * answer + (s[i]-'A') + 10;}
		if(islower(s[i])){answer = 16 * answer + (s[i]-'a') + 10;}
	}
	return answer;
}
