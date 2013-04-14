/*
	how to get current working directory
*/
#include <sys/param.h> 
#include <unistd.h> 
#include <stdio.h> 

int main(void)
{
  char buf[MAXPATHLEN];
  if( getcwd( buf, MAXPATHLEN ) ) 
  {
    printf( "%s\n", buf );
  }
  return 0;
}
