/*
	Tier 3 : Part 4	:	Question 6
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<assert.h>
#include "error_log.h"

int main ()
{
	char bad_string[20];
	strcpy(bad_string,"This was a bad string");
	
	log_error(bad_string,"%s")
	
	return 0;
}