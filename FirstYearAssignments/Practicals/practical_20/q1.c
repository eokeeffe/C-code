/*Evan O'Keeffe
  10324289
  practical 20 question 1
*/
#include <stdio.h>
int f1(int (*f) (int));
int f2(int i);

int main(void)
{
	printf("Results:%d\n",f1(f2));
	return 0;
}
int f1(int (*f)(int))
{
	int n =0;
	while ((*f)(n))
	{ 
		//printf("(*f)(n)=%d and n=%d\r\n",(*f)(n),n);
		n++;
	}
	printf("ending n=%d\r\n",n);
	return n;
}
int f2(int i)
{
	return (i * i + i - 12); //returns ((i*i)+i)-12), i.e if i=1 , ((1*1)+1)-12)=1+1=2-12=-10 , i=2 , ((2*2)+2)-12)=4+2-12=-6 
							 // finally i=3 , 3*3+3-12=9+3-12=12-12=0 and the loop stops at this number and returns the 
							 // value n which is 3
}