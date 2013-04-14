/*Evan O'Keeffe
  10324289
  This is joes example for finding the largest value through user input
  index point where the number is found was added by me*/
#include <stdio.h>
#include <stdlib.h>

void read_list( int list[], int len );
int find_entry( int list[], int len, int item );
int find_index( int list[], int len );
void prompt ( char msg[], char reply[] );


int main( void)
{		
		int  found,found1,i,item,item1,l[200] ;
	
		char num[100],choice[100];
		read_list ( l, 10 ) ;
		/*for(i=0;i<100;num[100]='\0')*/
		/*for(i=0;i<100;choice[100]='\0')*/

		prompt( "Enter numner to be found in the list: ",  num);
		
		item1= item;
		item = atoi( num );

		found = find_entry( l, 10, item );
		found1= find_place(1,10,item);
		
		if ( found != -1&&found != -1 )
			{printf(" %d is in the list at element %d\n", item , item1) ;}
		else{printf(" %d does not occur in the list \n", item );}
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

int find_entry( int list[], int len, int item )
{
	int i = 0;

	while ( i < len ) 
	{
		if ( list[i] == item )   /* Found it ?  */
			return( i );
		else
				i++ ;   /* Not found - check next element */
	}
	return( -1 ); /* Reached end of list and not found */
}
int find_index( int list[], int len )
{
	int i = 0;

	while ( i < len ) 
	{
		if ( list[i] == item )   /* Found it ?  */
			return( i );
		else
				i++ ;   /* Not found - check next element */
	}
	return( -1 ); /* Reached end of list and not found */
}

void prompt( char msg[], char reply[] )
{
	printf("%s ", msg );
	gets( reply );
}
