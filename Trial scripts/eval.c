#include<stdio.h>

int main()
{
	int a,b,c,d;
	float answer;
	
	answer = (float) sizeof(a/(b+c*d)) +((a && b) || c) % d;
	
	printf("answer=%f \r\n", answer);
	
	return 0;
}