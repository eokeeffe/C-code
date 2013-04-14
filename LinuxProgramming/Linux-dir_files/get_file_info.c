/*
	How do I obtain file information, like size, creation date, etc?

	Use stat( ), or use lstat() for symbolic links and fstat() for open file descriptors.

	int stat(const char *file_name, struct stat *buf);
	int fstat(int filedes, struct stat *buf);
	int lstat(const char *file_name, struct stat *buf);
*/
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h> 

struct stat sb;
if (stat("filename", &sb) == 0)
{
  printf("Size: %d\n", sb.st_size);
  printf("Last access: %s\n", ctime(&sb.st_atime));

  /* ... */
}