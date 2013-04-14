/*Evan O'Keeffe
  10324289
  This is joes example for finding the largest value and tells you were it is
  I added the min values function and the other parameters for min*/
#include <stdio.h>
#include <stdlib.h>

void read_list( int list[], int len );
int find_maxindex1( int list[], int len);
int find_minindex2( int list[], int len);/*Added by me afterwards*/

int Index1 ; /* Position of largest value in list */
int Index2 ; /*Added by me afterwards*/

int main( void)
{
	int  max,min, l[200] ;
		read_list ( l, 10 ) ;
		max = find_maxindex1( l, 10 );
		min = find_minindex2( l, 10 );/*Added by me afterwards*/
		printf("%d is the max value in list ", max ) ;
		printf("and it occurs at element %d in the list\n", Index1 );
		printf("%d is the min value in list ", min ) ;
		printf("and it occurs at element %d in the list\n", Index2 );
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


int find_maxindex1( int list[], int len )
{
	int i=0, max ;

	/*Index1 = 0 ;*/
	max = list[0] ;
	for ( i= 1; i < len; i++ )
	{
		if ( list[i] > max )
		{
					max = list[i] ;
					Index1 = i ;
		}
	}
	return( max );
}
int find_minindex2( int list[], int len )/*Added by me afterwards*/
{
	int i=0, min ;

	/*Index2 = 0 ;*/
	min = list[0] ;
	for ( i= 1; i < len; i++ )
	{
		if ( list[i] < min )
		{
					min = list[i] ;
					Index2 = i ;
		}
	}
	return( min );
}

