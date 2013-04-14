/*Evan O'Keeffe
  10324289
  practical 12 question 1
  prints the size of the int array , i.e prints how many elements are in it, which is 10
*/
#include<stdio.h>

#define NUMELEMS(a) \
printf("your result =%d \r\n",((sizeof(a))/(sizeof(a[0]))));

int main()
{
	int a[10],b;
	int i;
	
	printf("\nPlease enter value for the array in [%d]\r\n",i);
	scanf("%d",&a[0]);take the first element of the array
	
	NUMELEMS(a);
	
	return 0;
}