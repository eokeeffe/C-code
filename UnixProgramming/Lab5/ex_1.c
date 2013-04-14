#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int getlinel(char s[],int lim);
void escape(char* s, char* t);

int main()
{
	char input[MAXLINE];
	char output[MAXLINE];
	int i;
	for(i=0;i<MAXLINE;i++){input[i]=output[i]='\0';}
	int len;
	while ((len = getlinel(input, MAXLINE)) > 0)
	{
		escape(input, output);
		printf("%s\n", output); 
	}
	return 0;
}

// getline: read a line into s, return length
int getlinel(char s[],int lim) 
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n') 
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void escape(char* s, char* t) 
{
	int i=0,j=0;
	
	while( s[i] != '\0')
	{
		switch(s[i])
		{
			case '\n':
			{
				t[j]='\\';
				j++;
				t[j]='n';
				
				j++;
				i++;
				
				break;
			}
			case '\t':
			{
				t[j]='\\';
				j++;
				t[j]='t';
				
				j++;
				i++;
				
				break;
			}
			default:
			{
				t[j] = s[i];
				j++;
				i++;
				break;
			}
		}
	}
}