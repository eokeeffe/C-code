#include<stdio.h>

void recurse ( int size )
{
  if ( size == 0 )   // No recurse can be smaller than 1 atom (10^0==1) so doesn't call itself
    return;          // Return does not have to return something, it can be used
                     //  to exit a function
  recurse ( size - 1 ); // Decrements the size variable so the next recurse will be smaller.
}
int main()
{
  recurse ( 10 ); //Starts off with a large recurse (it's a logarithmic scale)
}