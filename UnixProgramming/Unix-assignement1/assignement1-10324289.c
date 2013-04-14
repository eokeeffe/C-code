/*
	assignement1-10324289
	Name:	Evan O'Keeffe
	S#:		10324289
	email:	evanokeeffe@gmail.com
	date started:15/02/2012
	date Finished:15/02/2012
	
	My personal program has to do this:
	
	4289 Shortest directory name beginning with [0-9]
	
*/
#include<stdio.h>
#include<string.h>
//for all global variables and function definitions please
//check the included header file
#include "Definitions.h"

int main()
{
	initialize(0);
	readinFiles();
	//printList();
	find();
	
	return 0;
}

int initialize(int d)//set all global variables to zero
{
	NumofElements=0;
	NumofFiles=0;
	debug = d;
	return 0;
}

int currentGlobals()//debugging function
{
	printf("#elements:%d\r\n",NumofElements);
	printf("#Files:%d\r\n",NumofFiles);
	if(debug==0){printf("debug is off\r\n");}
	if(debug==1){printf("debug is on\r\n");}
	return 0;
}

int readinFiles()
{
	int c;
	int stringNum=0,character=0;
	int count=0;
	
	//while the EOF hasn't been set off
	while(c != EOF)
	{
		if(c=='\n')//if the end of line reset the character placement
		{
			stringNum++;//go to the next string array
			character=0;//reset the character count to 0
			NumofElements++;//globally say that the number of 
						//strings is +1
		}
		c = getchar();//get the next character
		list[stringNum].array[character] = c; // place that character into the character place
		
		//debugging list
		if(debug){putchar(list[stringNum].array[character]);}
		
		character++;
	}
	return 0;
}

int printList()
{
	int countx,county;
	for(countx=0;countx<NumofElements;countx++)
	{
		printf("%s",list[countx].array);
	}
	return 0;
}

int find()
{
	struct string L[NumofElements];//create a new list that hold all names in the main list
	
	int count;
	for(count=0;count<NumofElements;count++)
	{
		//if(debug==1){printf("%c\r\n",list[count].array[0]);}
		
		//if the first element is a number from 0-9 and / is in the name (only directories have them
		if( (list[count].array[0]>='0') 
		    && 
			(list[count].array[0]<='9')
			&&
			(strstr(list[count].array,"/")!=NULL)//will return null if there is no occurence of "/" in the string at all
		   )
		{
			strcpy(L[NumofFiles].array,list[count].array);//place the string from the main loop to the new string array
			NumofFiles++;
		}
	}
	if(debug){printf("There are %d number of strings with numbers at the start\r\n",NumofFiles);}
	if(debug)
	{
		for(count=0;count<NumofFiles;count++)
		{
			printf("%s",L[count].array);
		}
	}
	
	if(NumofFiles==0)//if there are none then well tell me
	{
		printf("There are no files beginning with any numbers\r\n");
		return 0;
	}
	else
	{
		int lowest,num,c=0;

		lowest = strlen(L[0].array);//set the lowest value to the first string length
		num = 0;//this is used to just point to the specific place in the array 
		        //the smallest string occurs at
		
		if(debug){printf("\r\n");}
		
		for(count=0;count<NumofFiles;count++)
		{
			num = (strlen(L[count].array));//find each string length
			if(debug)
			{
				printf("count=%d\r\n",count);
				printf("%s:length=%d\r\n",L[count].array,(strlen(L[count].array)));
			}
			if(lowest >= num)//if the new string length is smaller then the current lowest
			{				 //then the lowest is the new string length
				c=count;	//keep track of where in the array the smallest is
				lowest = num;
			}
		}
		printf("The shortest file name with numbers[0-9] at the beginning is\r\n");
		printf("%s\r\n",L[c].array);//print the answer
		
		return 0;
	}
}
