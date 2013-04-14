/* Evan O'Keeffe
   10324289
   practical 14 question3
*/
#include<stdio.h>
int a;

void f(int b)//no d,g or e
{
	int c;
	printf("f(int b)\r\n");
	printf("a=%d\r\n",a);
	printf("b=%d\r\n",b);
	printf("c=%d\r\n",c);
	//printf("d=%d\r\n",d);
	//printf("e=%d\r\n",e);
	printf("f=%d\r\n",f);
	//printf("g=%d\r\n",g);
}

void g(void)//b,c,d,e or not declared here
{
	printf("g(void)\r\n");
	printf("a=%d\r\n",a);
	//printf("b=%d\r\n",b);
	//printf("c=%d\r\n",c);
	//printf("d=%d\r\n",d);
	//printf("e=%d\r\n",e);
	printf("f=%d\r\n",f);
	printf("g=%d\r\n",g);
	
	int d;
	{
		int e;
		printf("e declaration\r\n");
		printf("a=%d\r\n",a);
		//printf("b=%d\r\n",b);
		//printf("c=%d\r\n",c);
		printf("d=%d\r\n",d);
		printf("e=%d\r\n",e);
		printf("f=%d\r\n",f);
		printf("g=%d\r\n",g);
	}
		printf("d declaration\r\n");
		printf("a=%d\r\n",a);
		//printf("b=%d\r\n",b);
		//printf("c=%d\r\n",c);
		printf("d=%d\r\n",d);
		//printf("e=%d\r\n",e);
		printf("f=%d\r\n",f);
		printf("g=%d\r\n",g);
}

int main(void)//b ,c ,d ,e are not declared here
{
	int f;
	printf("main show\r\n");
	printf("a=%d\r\n",a);
	//printf("b=%d\r\n",b);
	//printf("c=%d\r\n",c);
	//printf("d=%d\r\n",d);
	//printf("e=%d\r\n",e);
	printf("f=%d\r\n",f);
	printf("g=%d\r\n",g);
}