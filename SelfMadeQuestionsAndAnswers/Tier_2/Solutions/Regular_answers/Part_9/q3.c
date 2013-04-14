/*
	Tier 2 : Part 9	:	Question 3
	
	what is contained in the places at A[0][1],A[0][3],A[1][1],A[1][3]
	
	Answers:
	A[0][1]=2
	A[0][3]=4
	A[1][1]=6
	A[1][3]=8
	
	Explanation :
	
	A[0][0]=1		A[1][0]=5
	A[0][1]=2		A[1][1]=6
	A[0][2]=3		A[1][2]=7
	A[0][3]=4		A[1][3]=8
	
	The number one thing to remeber here is that when K&R created C they had all arrays act like a 1-Dimensional
	they will act the exact same way in the memory allocation and the only difference is how you treat the 
	pointer arithmetic
	
	A[0] is a nice way of programming but is just a easy way of writing 
	*(A+1) 
	for a 2-d array the pointer is the same only change it to suit 2 dimensions
	A[0][0] is the easy way of doing 
	*((A+1)+1)
	and so on for N number of arrays
*/
#include<stdio.h>

int main()
{
	int A[4][4]={{1,2,3,4},{5,6,7,8}};
	int loop_count_1 = 0,loop_count_2 = 0,overall_count = 0;
	
	while(loop_count_1<2)
	{
		loop_count_2 = 0;
		
		while(loop_count_2<4)
		{
			printf("A[%d][%d]=%d\r\n",loop_count_1,loop_count_2,*(*(A+loop_count_1)+loop_count_2));
			
			loop_count_2++;
			overall_count++;
		}
		
		if(loop_count_1==0){printf("\r\n");}
		loop_count_1++;
	}
	printf("A[%d][%d] = %d\r\n",0,3,*(*(A+0)+3));
	
	return 0;
}