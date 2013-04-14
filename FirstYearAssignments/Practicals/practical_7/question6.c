/*Evan O'Keeffe
  10324289
  practical7 question6
*/
#include<stdio.h>

struct dialing_code
{
	char *country;
	int code;
};

const struct dialing_code country_code[]=
{
	{"Argentina",54},
	{"Bangladesh",880},
	{"Brazil",55},
	{"China",86},
	{"Columbia",57},
	{"Ethiopia",251},
	{"Egypt",20},
	{"France",33},
	{"Germany",49},
	{"India",91},
	{"Italy",39},
	{"Japan",81},
	{"Mexico",52},
	{"Poland",48},
	{"Russia",7},
	{"Spain",34},
	{"Sudan",249},
	{"Turkey",90},
	{"UnitedStates",1},
	{"Vietnam",84}
};

int main()
{
	int c,i=0;
	printf("Please enter a number\r\n");
	scanf("%d",&c);
	while(i<20)
	{
		if(country_code[i].code==c){printf("%s\r\n",country_code[i]);break;}
		else
		 {i++;}
	}
	if(i==20){printf("Sorry but your number isn't here\r\n");}
	return 0;
	
}
	