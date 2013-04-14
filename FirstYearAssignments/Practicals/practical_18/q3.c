/*Evan O'Keeffe
  10324289
  practical 18 question3
  2 errors in the function sort_vector , the type cast was left out as the program works
  had to leave it as my real question was deleted when a worm virus nuked my laptop
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR printf("memory allocation failed\r\n");


void sort_vector (int n,int m,int *x,char* p[40]) 
{
	int i, item, temp ;
	char* temp1;
	for (item = 0; item < n-1; ++item) 
	{
	// find the smallest of all remaining elements
		for (i = item+1; i < n; ++i) 
		{
			if (*(x + i) <*(x + item)) 
			{
			// interchange both the two elements of the date and also the elements of the strings
			//of the date
			//string arrange
				temp=p[item];
				p[item]=p[i];
				p[i]=temp;
			//date re-arrange
				temp = *(x + item) ;
				*(x + item) = *(x + i);
				*(x + i) = temp;
			}
		}
	}
}

int main () 
{
	int i,n, m, *x ;
	
	printf ("Please enter No. of reminders\n") ;
	scanf("%d", &n);
	printf("\n") ;
	printf ("Please enter max_lenght of reminders\n") ;
	scanf("%d", &m);
	printf("\n") ;
	
	char *p[n];
	
	x = (int *) calloc(n , sizeof(int)) ; // allocate memory for x
	if(x!=NULL)
	{
		for(i=0;i<n;i++)
		{
			p[i]=(char* )calloc(m,sizeof(char)*m);//allocate memory for each string pointer
			if(p[i]!=NULL){continue;}
			else
				{
					ERROR
					break;
				}
		}
	}
	else{ERROR}
	
	for (i = 0; i < n; ++i) 
	{
		printf("reminder date no:%d\r\n", i+1);
		scanf ("%d%*c", x + i) ; // read the list of numbers
		printf("reminder for no:%d is\r\n", i+1);
		scanf("%s",p[i]);
	}
	sort_vector (n,m,x,p) ;
	
	for (i = 0; i < n; ++i) 
	{
		printf("date:%d , reminder:%s\n", *(x + i), p[i]) ;
	}
	free(x);
	for(i=0;i<n;i++)
	{
		free(p[i]);
	}
	return 0 ;
}