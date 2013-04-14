#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>

static int ASSERT_ON = 1;
static int ASSERT_OFF= 0;

void error(int e,int assert_on);

void error(int e,int assert_on)
{
	//common error function 
	//will return errno + a string where the user specifies the 
	//function that it occured in
	
	strerror("%d=%s\r\n",e,perror(strerror(e));
	//reset the errno
	errno=0;
	//if needed end the program right now
	if(assert_on==ASSERT_ON){assert(errno!=0);}
}
