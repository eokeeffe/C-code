/*Evan O'Keeffe
  10324289 
  practical 11 question1
  program that uses the short assignements for *+-/ 
*/
#include<stdio.h>
int main()
{
	int i,j,k;
	
	//part a
	i=7;
	j=8;
	i *=j+1;//equiv to i = i*j+1
	printf("partA:%d %d\r\n",i,j);
	
	//part b
	i=j;
	j=k;
	i +=j +=k;//equiv to i = i+j => i+j+k
	printf("partB:%d %d %d\r\n",i,j,k);
	
	//part c
	i=1;
	j=2;
	k=3;
	
	i -=j -=k;//equiv to i = i-j => i-j-k
	printf("partC:%d %d %d\r\n",i,j,k);
	
	//part d
	i=2;
	j=1;
	k=0;
	i *= j *= k;//equiv to i = i*j => i*j*k
	printf("partD:%d %d %d\r\n",i,j,k);
	
	return 0;

}