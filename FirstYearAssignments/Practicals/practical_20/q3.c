/*Evan O'Keeffe
  10324289
  practical20 question 3
*/
#include<stdio.h>
#include<stdlib.h>
int opt(int ( *pt )(int),int x);//function defintion is a 
								//return type of int with arguements of a pointer to a function with one int arguement and an int arguement
int toto(int x);
int tata(int x);

int toto(int x)
{
	return (x*3);
}
int tata(int x)
{
	return (x*5);
}
int opt(int ( *pt )(int x),int x)
{
	int result=(*pt)(x); //put the result of the function passed with parameter x into result and return it
	return result;
}
int main()
{
	printf("%d\n", opt(toto,5));//use the function toto with and pass 5 as the parameter
	printf("%d\n", opt(tata,5));//use the function tata with the int paramenter as 5
	return 0;
}