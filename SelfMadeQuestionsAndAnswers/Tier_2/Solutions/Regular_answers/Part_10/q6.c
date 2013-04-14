/*
	Tier 2 : Part 10	:	Question 6
*/
#include<stdio.h>

int swap_ints(int *a,int *b);

int main()
{
	int *pointer_1,*pointer_2;
	int a=12,b=20;
	
	pointer_1=&a;
	pointer_2=&b;
	
	printf("Before swap\r\n");
	printf("a=%d and b=%d\r\n",*pointer_1,*pointer_2);
	printf("a is held in :%d and b is held in :%d\r\n",pointer_1,pointer_2);
	
	swap_ints(pointer_1,pointer_2);
	
	printf("After the swap\r\n");
	printf("a=%d and b=%d\r\n",*pointer_1,*pointer_2);
	printf("a is held in :%d and b is held in :%d\r\n",pointer_1,pointer_2);
	
	
	return 0;
}
int swap_ints(int *a,int *b)
{
	int temp_variable;
	
	temp_variable = *a;
	
	*a = *b; 
	
	*b = temp_variable;
	
	return ;
}