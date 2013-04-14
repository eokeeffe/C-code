#include <stdio.h>
#include <setjmp.h>
 
jmp_buf test1;
 
void tryjump()
{
    longjmp(test1, 3);
}
 
int main (void)
{
    if (setjmp(test1)==0) {
        printf ("setjmp() returned 0.");
        tryjump();
    } else {
        printf ("setjmp returned from a longjmp call.");
    }
}