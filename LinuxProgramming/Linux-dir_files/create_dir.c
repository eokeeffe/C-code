/*
	How do I create and remove a directory?
*/
#include <sys/types.h> 
#include <sys/stat.h> 

if (mkdir("foo", S_IRWXU) != 0)
{
  /* mkdir( ) error */
}

if (rmdir("foo") != 0)
{
  /* rmdir( ) error */
}

