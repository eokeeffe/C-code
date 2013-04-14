#include<stdio.h>
#include<stdlib.h>
#define BUFFER 100
#define MAXNUMEQ 50
struct string
{
    char stack[BUFFER];
}a;

int push(char op);//push character onto the stack
int pop();//pop the last element
int Getsize();//return stack size
int STACK_INITIALIZE();//set the numbers
int readStream();//read in the equation
int isOP(char op);//is the character an operation
int equation(int a, int b, char op);//do the equations

int size;
int numOfeq;
int position;
int array[MAXNUMEQ];


int push(char op)
{
    if(Getsize() == BUFFER)
    {
        return 0;
    }
	position++;
    size++;
    a.stack[position] = op;
    return 1;
}

int pop()
{
    if(Getsize() == 0){return 0;}
    int temp = a.stack[position];
    a.stack[position] = '\0';
    position--;
    size--;
    return temp;
}

int Getsize()
{
    return size;
}

int STACK_INITIALIZE()
{
    size=0;
    position=-1;
	numOfeq=0;
}

int isOP(char op)
{
	switch(op)
	{
		case '+':
		{
			return 1;
		}
		case '-':
		{
			return 1;
		}
		case '*':
		{
			return 1;
		}
		case '/':
		{
			return 1;
		}
		default:
		{
			return 0;
		}
	}
}

int readStream()
{
	char c;
	while( c != EOF)
	{
		c = getchar();
		if( isOP(c) )
		{
			numOfeq++;
		}
		push(c);
	}
	return 0;
}

int equation(int a, int b, char op)
{
	switch(op)
	{
		case '+':
		{
			return (a+b);
		}
		case '-':
		{
			return (a-b);
		}
		case '*':
		{
			return (a*b);
		}
		case '/':
		{
			if(b==0)
			{return 0;}
			else
			{return (a/b);}
		}
		default:
		{
			return 0;
		}
	}
}

int doEquations()
{
	int count=0;
	while(count < Getsize())
	{
		
	}
}

int main()
{
	STACK_INITIALIZE();
	readStream();
	
    printf("%s\r\n",a.stack);
	printf("numOfeq:%d\r\n",numOfeq);
	
    return 0;
}