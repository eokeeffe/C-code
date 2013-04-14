/*
Name:	Evan O'Keeffe
S#:		10324289
Email:	evanokeeffe@gmail.com

Program takes 2 octal numbers and one of 3 operators
-,*,/ all others generate a suitable error message

answer returned is printed in decimal form
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct eq//I like to work with structs
{
	int a,b;
	char op,equal;
}b;

//suitable error message function
void ERROR(char s[],char op,int e);
//get the input for the equation
int octalInput();
//do the opeartion on the numbers and return an answer
int getAnswer();

int main()
{
	octalInput();//first input
	
	if(b.equal != '=' && (b.op != '-'||
						  b.op != '*'||
						  b.op != '/')
		)
	{//second to show that the first wasn't correct
		octalInput();
	}
	//get the answer
	int answer = getAnswer();
	//print the answer
	printf("%d",answer);
	//return successful execution to kernel
	return EXIT_SUCCESS;
}

int octalInput()
{/*Take the input from the user*/
	while( (scanf ("%o %c %o %c", &b.a,&b.op,&b.b,&b.equal)) != 4)//%o takes octal input
	{
		//if input is incorrect print this
		fprintf(stderr,"format is\r\n");
		fprintf(stderr,"number op number =\r\n");
		//and flush the input buffer
		fflush(stdin);
	}
	//debug statement
	//printf("%o %c %o %c\r\n",b.a,b.op,b.b,b.equal);
	return 1;
}

int getAnswer()
{/*do the operation on the numbers*/
	int answer=0;//dealing with whole numbers here
	switch(b.op)
	{
		case '-':
		{
			answer = b.a - b.b;
			if (answer < 0){	return 0; }//integers are positive for this assignment
			return answer;
		}
		case '*':
		{
			answer = (b.a * b.b);
			return answer;
		}
		case '/':
		{
			if(b.b <= 0)//check for zero divisibility
			{//33 is zero division error ,EDOM is the error title
				ERROR("Division by zero",' ',33);
			}
			answer = b.a / b.b;
			return answer;
		}
		default://safety net for other operands that could be '+' or anything else
		{
			ERROR("operation not allowed",b.op,22);
		}
	}
}

void ERROR(char s[],char op,int e)
{//print an error message and exit the program with
 //failure status
	if(op==' ')//not an operand problem
	{
		fprintf(stderr,"%d:%s|%s\r\n",e,strerror(e),s);
	}
	else//operand problem
	{
		fprintf(stderr,"%d:%s|'%c' %s\r\n",e,strerror(e),op,s);
	}
	exit(EXIT_FAILURE);
}

