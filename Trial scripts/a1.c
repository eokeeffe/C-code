/* Inline assmebler in C example 1*/

#include<stdio.h>

int main()
{
   __asm__("movl %esp,%eax");
 
  return 0;
}