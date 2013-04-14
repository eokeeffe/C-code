/*
	The st_mode member contains information about the file type and access permissions.
*/
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h> 

struct stat s;
int         i;
int         modes[] = {
  S_IRUSR, S_IWUSR, S_IXUSR, 
  S_IRGRP, S_IWGRP, S_IXGRP, 
  S_IROTH, S_IWOTH, S_IXOTH 
};

if (stat("filename", &s) == 0)
{
  for (i = 0; i < 9; ++i)
  {
    if (modes[i] & s.st_mode)
    {
      putchar("rwx"[i % 3]);
    }
    else
    {
      putchar('-');
    }
  }
}

