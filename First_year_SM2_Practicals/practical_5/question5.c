/*Evan O'Keeffe
  10324289
  practical 5 question5
*/
#include<stdio.h>

int* sorting1(int array1[10]);
int* sorting2(int array2[10]);
int* sorting3(int result[20]);
void mergematrix(int array1[10],int array2[10]);



void main()
{
	int array1[10],array2[10];
	int a=0,b=0;
	printf("Please enter the values for the first array here\r\n");
	
	while(a<10)
	{
		printf("number %d in array 1 is \r\n",a,b);
		scanf("%d",&array1[b]);
		a++;
		b++;
	}
	sorting1(array1);
	
	a=0;
	b=0;
	printf("Now please enter the values for array number 2\r\n");
	while(a<10)
	{
		printf("number %d in array 2 is \r\n",a,b);
		scanf("%d",&array2[b]);
		a++;
		b++;
	}
	sorting2(array2);
	mergematrix(array1,array2);
	
}
int* sorting1(int array1[10])
{
	int N=10;
	int tempo;
	int i, j ;
	for ( i = 1 ; i <= N-1 ; i++) 
	{
		for ( j = i+1; j < N; j++) 
		{
			if ( array1[i] < array1[j] ) 
			{
				tempo = array1[i] ; array1[i] = array1[j] ; array1[j] = tempo ;
			}
		}
	
	
	for (j = 0; j < N; j++) 
	{ printf (" %d ", array1[j]);} 
	printf ("\n");
	}
	
	return array1;
}
int* sorting2(int array2[10])
{
	int N=10;
	int tempo;
	int i, j ;
	for ( i = 1 ; i <= N-1 ; i++) 
	{
		for ( j = i+1; j < N; j++) 
		{
			if ( array2[i] < array2[j] ) 
			{
				tempo = array2[i] ; array2[i] = array2[j] ; array2[j] = tempo ;
			}
		}
	
	for (j = 0; j < N; j++) 
	{ printf (" %d ", array2[j]);} 
		printf ("\n");
	}
	return array2;
}
int* sorting3(int result[20])
{
	int N=20;
	int tempo;
	int i, j ;
	for ( i = 1 ; i <= N-1 ; i++) 
	{
		for ( j = i+1; j < N; j++) 
		{
			if ( result[i] < result[j] ) 
			{
				tempo = result[i] ; result[i] = result[j] ; result[j] = tempo ;
			}
		}
	
	//for (j = 0; j < N; j++) 
	//{ printf (" %d ", result[j]);} 
		//printf ("\n");
	}
	return result;
}
void mergematrix(int array1[10],int array2[10])
{
	int result[20];
	int a=0;
	int b=0;
	int c=0;
	while(a<10)
	{
		while(b<10)
		{
			result[b]=array1[b];
			//printf("%d\t",result[b]);
			b++;
		}
		a++;
	}
	a=0;
	
	while(a<10)
	{
		
		while(b<20)
		{
			result[b]=array2[c];
			//printf("%d\t",result[b]);
			b++;
			c++;
		}
		a++;
	}
	sorting3(result);
	b=0;
	while(b<20)
	{
		printf("%d\t",result[b]);
		b++;
	}
}