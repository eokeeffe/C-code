/*Evan O'Keeffe
  10324289
  this program is my first attempt of using assembler in C
  Whats happening here is that I'm using inline assmebler 
  to add the numbers 10(foo) and bar(15) together and output an answer*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(void)
{
        int foo = 10, bar = 15;
        __asm__ __volatile__("addl  %%ebx,%%eax":"=a"(foo):"a"(foo), "b"(bar));
        printf("foo+bar= %d \n",foo);
        return 0;
}