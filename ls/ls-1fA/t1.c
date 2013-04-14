/*
	assignement1-10324289
	Name:	Evan O'Keeffe
	S#:		10324289
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

int initialize(int d)
{
	NumofElements=0;
	NumofFiles=0;
	debug = d;
	return 0;
}

int currentGlobals()
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
	
	while(c != EOF)
	{
		if(c=='\n')
		{
			stringNum++;//go to the next string array
			character=0;//reset the character count to 0
			NumofElements++;//globally say that the number of 
						//strings is +1
		}
		c = getchar();//get the next character
		list[stringNum].array[character] = c;
		
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
	struct string L[NumofElements];//create a new list that hold all names
	
	int count;
	for(count=0;count<NumofElements;count++)
	{
		//if(debug==1){printf("%c\r\n",list[count].array[0]);}
		
		if( (list[count].array[0]>='0') 
		    && 
			(list[count].array[0]<='9')
			&&
			(strstr(list[count].array,"/")!=NULL)
		   )
		{
			strcpy(L[NumofFiles].array,list[count].array);//place list into new list L
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
	
	if(NumofFiles==0)
	{
		printf("There are no files beginning with any numbers\r\n");
		return 0;
	}
	else
	{
		int lowest,num,c=0;

		lowest = strlen(L[0].array);
		num = 0;
		
		if(debug){printf("\r\n");}
		
		for(count=0;count<NumofFiles;count++)
		{
			num = (strlen(L[count].array));
			if(debug)
			{
				printf("count=%d\r\n",count);
				printf("%s:length=%d\r\n",L[count].array,(strlen(L[count].array)));
			}
			if(lowest >= num)
			{
				c=count;
				lowest = num;
			}
		}
		printf("The shortest file name with numbers[0-9] at the beginning is\r\n");
		printf("%s\r\n",L[c].array);
		
		return 0;
	}
}