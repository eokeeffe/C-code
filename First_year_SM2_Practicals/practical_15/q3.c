/*Evan O'Keeffe
  10324289
  practical 15 question3
  
  to save you time for the testing , i put in a random selection of words for you 
  the first print through shows the words in un-ordered sortment
  then they go through the bubble sort and are printed in 
  alphabetical order
  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR printf("%d\r\n",__LINE__);

struct W
{
	char* array1;
};
//this array is defined as lenght 11 for safety reasons during the sort loop
struct W array2[11]={
	{"android"},
	{"world"},
	{"universe"},
	{"hello"},
	{"insanity"},
	{"fringe"},
	{"science"},
	{"robot"},
	{"googleplex"},
	{"apple"}
};
struct W array3[20];//the words in array2 are placed in here
struct W array4[20];//this is a temp array used for re-arranging the values in array3


int main()
{
	int a,i;
	printf("\n\nUnordered array\r\n");
	for(i=0;i<10;i++)
	{
		printf("string[%d]:%s\r\n",i,array2[i]);//print un-ordered array
		array3[i].array1=array2[i].array1;//while also placing each element in array2 in array3
	}
	printf("\n");
	printf("Sorting part here\r\n");
	a=0;
	while(a<10)//10 times covers each word in the array
	{
		for(i=0;i<9;i++)//keep the value less than 10 as 10+1=\0 , this would cause a crash
		{
			//ERROR
			//printf("%d:%c\r\n",i,array3[i].array1[0]);
			
			if(array3[i].array1[0]>array3[i+1].array1[0])//BUBBLE SORTING TIME
			{
			
				//printf("0:%s\r\n",array3[i].array1);
				//printf("1:%s\r\n",array3[i+1].array1);
				
				array4[i].array1 = array3[i].array1;
				array3[i].array1 = array3[i+1].array1;
				array3[i+1].array1 = array4[i].array1;

				//printf("0:%s\r\n",array3[i].array1);
				//printf("1:%s\r\n",array3[i+1].array1);
			}
		}
		a++;
	}
	printf("\n");
	printf("Ordered array\r\n");
	for(i=0;i<10;i++)//print ordered array
	{
		printf("string[%d]:%s\r\n",i,array3[i].array1);
	}
	return 0;
}