#include<stdio.h>

#define file printf(" %s \r\n",__FILE__)
#define date printf(" %s %s\r\n",__DATE__,__TIME__)
#define line printf(" %d \r\n",__LINE__)
#define version printf(" %s stdc%d\r\n",__VERSION__,__STDC__)

int main()
{
	file;
	date;
	line;
	version;
	
    int i_value   = 16777217;
    float f_value = 16777217.0;
    printf("The integer is: %i\n", i_value);
    printf("The float is:   %f\n", f_value);
    printf("Their equality: %i\n", i_value == f_value);
	
	return 0;
}