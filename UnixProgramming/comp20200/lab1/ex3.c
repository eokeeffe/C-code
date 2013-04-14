#include<stdio.h>
void Convert_to_fahr(int a);

int main()
{
	Convert_to_fahr(300);
	return 0;
}

void Convert_to_fahr(int a)
{
	int fahr,celsius;
	int lower=0,step=20;
	fahr=lower;
	while(fahr<=a)
	{
		celsius = 5*(fahr-32)/9;
		if(fahr==0)
		{
			printf("Fahr\tCelsius\r\n");
		}
		printf("%d\t%d\n",fahr,celsius);
		fahr+=step;
	}
}
