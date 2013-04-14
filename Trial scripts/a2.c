/* Inline Assembler example 2*/
#include <stdio.h>
#include <unistd.h>
 
int main()
{
  int data1 = 2, data2 = 3;
 
  // Fancy assembly statement
  __asm__("addl  %%ebx,%%eax"
                    :"=a"(data1)
                    :"a"(data1), "b"(data2)
              );
 
  fprintf(stdout, "data1 + data2 = %d\n", data1);
 
  return 0;
}