/*Evan O'Keeffe
  10324289
  practical7 question5
*/

#include<stdio.h>
//A
/*
typedef struct
{
	char *a;
	char *b;
	char *c;
	
}colors;

void funct(colors sample);

int main()
{
	static colors sample={"red","green","blue"};
	printf("%s%s%s\n",sample.a,sample.b,sample.c);
	funct(sample);
	printf("%s%s%s\n",sample.a,sample.b,sample.c);
	return 0;
}
void funct(colors sample)
{
	 sample.a="cyan";
	 sample.b="magenta";
	 sample.c="yellow";
	 printf("%s%s%s\n",sample.a,sample.b,sample.c);
}
*/
//the program prints redgreenblue then cyanmagentayellow then redgreenblue again

//B
/*
typedef struct
{
	char *a;
	char *b;
	char *c;
}
colors; 

void funct(colors *pt);

int main()
{
	static colors sample={"red","green","blue"};
	printf("%s%s%s\n",sample.a,sample.b,sample.c);
	funct(&sample);
	printf("%s%s%s\n",sample.a,sample.b,sample.c);
}

void funct(colors *pt)
{
	pt->a="cyan";
	pt->b="magenta";
	pt->c="yellow";
	printf("%s%s%s\n",pt->a,pt->b,pt->c);
}
*/
//the program prints redgreenblue then cyanmagentayellow then cyanmagentayellow again