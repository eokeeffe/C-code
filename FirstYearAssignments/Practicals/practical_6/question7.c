/*Evan O'Keeffe
  10324289
  practical6 question7
*/
#include<stdio.h>
void find_two_largest(int a[],int n,int *largest,int *second_largest);

int main()
{
	int n;
	
	
	printf("Please enter the lenght of the array\r\n");
	scanf("%d",&n);
	
	int A[n];
	
	int i,a=0;
	
	for(i=0;i<n;i++)
	{
		printf("Please enter value for array # %d\r\n",i);
		scanf("%d",&A[i]);
	}
	printf("\n");
	int *largest=&A[0],*second_largest=&A[0];
	/*for(i=0;i<n;i++)
	{
		printf("%d=%d\r\n",a,A[i]);
		a++;
		
	} */
	
	find_two_largest(A,n,largest,second_largest);
	
	return 0;
}
void find_two_largest(int A[],int n,int *largest,int *second_largest)
{
	int i;
	//printf("HEllo\r\n");
	
	for(i=0;i<n;i++)
	{
		if(A[i]> *largest)
		{
			largest=&A[i];
		}
	}
	//printf("HEllo1\r\n");
	for(i=0;i<n;i++)
	{
		if(A[i]< *largest&&A[i]> *second_largest)
		{
			second_largest=&A[i];
		}
	}
	printf("Largest=%d , second_largest =%d \r\n",*largest,*second_largest);
}