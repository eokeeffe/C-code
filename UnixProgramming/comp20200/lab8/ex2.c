#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 200


struct date
{
	int day;
	int month;
	int year;
};

struct person
{
	char firstname[40];
	char lastname[40];
	struct date birthday;
	double height;
};

int main()
{

	FILE *fp_in, *fp_out;
	char *name_in = "people.txt";
	fp_in = fopen(name_in, "rb");
	struct person me;
	struct person array[MAX_LEN];
	int count;

	fread(&array, sizeof(struct person), MAX_LEN , fp_in);

	int max=0;
	for(count=0; count < MAX_LEN ;count++)
	{
		if(array[count].height>max)
		{
			max = array[count].height;
		}
	}

      while( printf("Name: %s %s:%.2lf\n", array[max].firstname, array[max].lastname, array[max].height) == 3);
     while( printf("DOB: %d/%d/%d\n",array[max].birthday.day,array[max].birthday.month,array[max].birthday.year) == 3);

	return 0;
}
