/*Evan O'Keeffe
  10324289
  practical 20 question 2
  
  part1: The first prototype has a return type of float and two floating point pointers as parameters
		 the second function is the same
		 The third function returns a floating point pointer and takes a float dataype function pointer with 2 floating point pointers as parameters
		 
  part2:The first prototype has a return type of float and two floating point pointers as parameters
		 the second function is the same
  
  part3:The main differences are that one and two return a float and three returns a pointer to a float
		also three takes a function of data-type float and 2 floating point pointers as parameters
  
  part4:Each time its called in main the function three takes the pointer to the function that its pointing to and then takes the parameters of whats at the 
        address of a and b and puts this into c , it then returns the address of c
  
*/
#include<stdio.h>
float one(float *px, float *py);
float two(float *px, float *py);
float *three ( float (*pt ) ( float *px, float *py) ) ;;
int main( )
{
	float *pa, *pb;
	pa = three(one);
	pb = three(two);
	return 0;
}

float one(float *px, float *py)
{
	float z;
	z = 10.0;
	return ( z ) ;
}
float two(float *pp, float *pq)
{
	float r;
	r= 30.0;
	return (r);
}
float * three(float (*pt)(float *px, float *py))
{
	float a, b, c;
	c = (*pt)(&a, &b);//takes the pointers of the function and the original agruements from the time it was called, if you want proof uncomment the printf
					  //below and see what happens each time its called
	printf("c=%f\r\n",c);
	return (&c);
}