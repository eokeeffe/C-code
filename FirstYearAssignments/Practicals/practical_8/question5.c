/*Evan O'Keeffe
  10324289
  practical8 question5
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

typedef union 
{
	float fexp; /* floating-point exponent */
	int nexp; /* integer exponent */
} nvals;

typedef struct 
{
	float x; 	/* value to be raised to a power */
	char flag ; /* 'f' if exponent is floating - point ,'i' if exponent is integer */
	nvals exp; /* union containing exponent */
} values;

values a;

//double exp(double x);	//returns the value of e raised to the xth power
//double log(double x);	//returns the natural logarithm (base-­-e logarithm) of x.
void power_int(int x);			//do the power function with int
void power_float(float x);			//do the power function with int

float answer;
int x;

void main()
{
	//char i='i',I='I',f='f',F='F';
	printf("Please enter whether n is an integer or float\r\n");
	printf("Please enter i for int or f for float\r\n");
	a.flag=getchar();
	
	//printf("HERE 1\r\n");
	
	if(a.flag=='i'||a.flag=='I')
	{
		//printf("GOTTA 1\r\n");
		printf("Function is y=x^n\r\n");
		printf("Please enter the value for n , Y=X^N\r\n");
		scanf("%d",&a.exp.nexp);
		power_int(a.exp.nexp);//n for the int
		
	}
	if(a.flag=='f'||a.flag=='F')
	{
		//printf("GOTTA 2\r\n");
		printf("Function is y=e^nlogx\r\n");
		printf("Please enter the value for n , y=e^nlogx\r\n");
		scanf("%f",&a.exp.fexp);
		power_float(a.exp.fexp);//n for the float
	}
		
}
void power_int(int x)
{
	int index;
	
	printf("Please enter value for x, for Y=X^N\r\n");
	printf("Remeber x is a floating point number\r\n");
	scanf("%f",&a.x);
	//printf("x=%f\r\n",a.x);//x value
	
	answer = (float)a.exp.nexp;//n changes from int to float
	//printf("base=%f\r\n",a.x);
	//printf("power=%f\r\n",answer);
	
    for(index = 1; index <= a.x-1 ; index++)
        {
			answer *= answer;
			//printf("answer = %f \r\n",answer);
		}
		printf("%f is your answer\r\n",answer);
	
}
void power_float(float x)
{
	int index;

	printf("Please enter value for x,for y=e^nlogx\r\n");
	printf("Remeber x is a floating point number\r\n");
	scanf("%f",&a.x);
	//printf("x=%f\r\n",a.x);//x value
	
	
	float multi = a.exp.fexp*log(a.x);//n*log(x)
	
	answer = exp(multi);//e^nlogx 
	//printf("exp=%f\r\n",exp(multi));
	//printf("answer=%f\r\n",answer);
	
    /*for(index = 1; index <= a.exp.fexp-1 ; index++)
        {
			answer *= multi;
		}
		*/
		printf("%f is your answer\r\n",answer);
}