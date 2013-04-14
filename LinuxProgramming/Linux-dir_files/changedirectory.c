/*
	change current working directory
*/
#include <unistd.h> 

if( chdir( "/new/cwd" ) != 0 ) 
{
  /* chdir( ) error */
}