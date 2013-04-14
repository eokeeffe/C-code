#include <stdio.h>
#include<string.h>
#include<assert.h>
#define MAXNUM 20    /* maximum input number length */

int btoi(char s[]);
void checkline(char s[]);

int main()
{
	int c, i;
	char binaryin[MAXNUM];

	for (i=0; i < MAXNUM-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	{
		binaryin[i] = c;
		//printf("%x:%c\r\n",c,c);
	}
	binaryin[i] = '\0';
	
	int answer;
	checkline(binaryin);
	answer = btoi(binaryin);

	printf("the answer in decimal = %d\r\n",answer);

	return 0;
}

void checkline(char s[])
{
	int count,value=1;
	for(count=0;count<strlen(s);count++)
	{
		if(s[count]!='1'||s[count]!='0')
		{
			value=0;
		}
	}	

	assert(value!=1);
}

int btoi(char s[])
{
	int answer;
	int i=0;
	for(answer=0;isdigit(s[i]);i++)
	{
		answer = 2 * answer + (s[i]-'0');
	}
	return answer;
}
