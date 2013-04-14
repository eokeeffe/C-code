/*
	how to use a dll file
	gcc using_my_dll.c a.dll -o using_my_dll
*/
#include<stdio.h>
#include<stdlib.h>
#include "a.h"

int main() 
{
  char              str[21];
  struct STRUCT_DLL S;
  int               i;

  S.count_int       = 10;
  S.ints            = malloc(sizeof(int) * 10);
  S.ME='E';
  
  printf("In using_my_dll.c ,S.ME = %c \r\n",S.ME);
  
  for (i=0; i<10; i++) 
  {
	S.ints[i] = i;
  }


  myFunc(42, str, &S);

  printf("str: %s\n", str);

}