/*Evan O'Keeffe
  10324289
  practical 13 question1
  the PRN didn't get pre-compiled as the function PRN was too far away from
  the parameters set for it , so it would return errors to the compiler
  the program prints X as expected 
  
  For the last part , question 4 
  the compiler shows the methods it uses to replace the function 
*/
#include <stdio.h>
#define PRN(x) printf("x\n");
int main ()
{
	PRN(Hello from main());
	return 0 ;
}