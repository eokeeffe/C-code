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
	fahr=a;
	while(fahr>=0)
	{
		celsius = 5*(fahr-32)/9;
		if(fahr==a)
		{
			printf("Fahr\tCelsius\r\n");
		}
		printf("%d\t%d\n",fahr,celsius);
		fahr-=step;
	}
}
