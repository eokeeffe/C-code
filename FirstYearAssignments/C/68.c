/*Evan O'Keeffe
  10324289
  This is joes example for finding the largest value
  Added a minimum value my self*/
#include <stdio.h>
#include <stdlib.h>

void read_list( int list[], int len );
int find_maximum( int list[], int len);
int find_minimum( int list[], int len);/*added by me*/

int main( void)
{
	int  max, min ,l[200] ;
		read_list ( l, 10 ) ;
		max = find_maximum( l, 10 );
		min = find_minimum( l, 10);/*added by me*/
		printf("Max value in list is: %d \n", max ) ;
		printf("Min value in list is: %d \n", min ) ;/*added by me*/
}

void read_list( int list[], int len )
{
	char entry[100];
	int i ;
	printf("Enter %d numbers, one per line\n", len);
	for( i =0; i < len; i++ )
	{
		gets( entry );
		list[i] = atoi( entry) ; /* convert to number */
	}
}

int find_maximum( int list[], int len )
{
	int i, max ;

	max = list[0] ;
	for ( i= 0; i < len; i++ )
	{
		if ( list[i] > max )
					max = list[i] ;
	}
	return (max);
}
int find_minimum( int list[], int len )/*added by me*/
{
	int i, min ;

	min = list[0] ;
	for ( i= 0; i > len; i++ )
	{
		if ( list[i] < min )
					min = list[i] ;
	}
	return (min);
}

