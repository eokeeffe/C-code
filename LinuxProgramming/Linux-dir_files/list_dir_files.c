/*
	read all filenames from a directory
*/
#include <dirent.h> 
#include <stdio.h> 

DIR           *d;
struct dirent *dir;
d = opendir(".");

if (d)
{
  while ((dir = readdir(d)))
  {
    printf("%s\n", dir->d_name);
  }
  closedir(d);
}