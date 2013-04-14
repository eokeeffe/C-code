/*Evan O'Keeffe
  10324289
  Multiple functions with a menu*/
#include <stdio.h>
#include <stdlib.h>

char option[200];

void display_menu(void);
void clear_screen(void);
void get_option(void);
void process_option(void);
void calc_triangle(void);
void calc_rectangle(void);
void calc_circle(void);
void wait_for_user(void);

void main()
{	
	display_menu();
	get_option();
	while(option[0]!='Q')
	{
		process_option();
		display_menu();
		get_option();
	}
}
void display_menu(void)
{
	clear_screen();
	printf("\n\n\n\n");
	printf("\t\tQ..............Quit\n");
	printf("\t\tC..............Circle\n");
	printf("\t\tR..............Rectangle\n");
	printf("\t\tT..............Triangle\n");
	printf("\n\n");
}
void get_option(void)
{
	printf("\t\tEnter Option:");
	gets(option);
}
void process_option(void)
{	
	int i=0;
	
	if((option[0]=='t')||(option[0]=='T')){calc_triangle();}
	else if((option[0]=='r')||(option[0]=='R')){calc_rectangle();}
	else if((option[0]=='c')||(option[0]=='C')){calc_circle();}
	else if((option[0]=='q')||(option[0]=='Q')){exit(0);}
	
	else 
	{
		printf("Invalid option %c\n",option[i]);
	}
	
	wait_for_user();
	
}
void clear_screen(void)
{
	int i;
	for(i=0;i<24;i++)
	printf("\n");
}
void calc_triangle(void)
{
	float area,base,perp_ht;
	char line[200];
	
	printf("\n\n Enter base and per.Height:\n\r");
	gets(line);
	sscanf(line,"%f%f",&base,&perp_ht);
	area=((base/2)*perp_ht);
	printf("\n\n Area=%f\n",area);
}
void calc_rectangle(void)
{
	float area,lenght,breadth;
	char line[200];
	printf("\n\n Enter the lenght and the breadth\n\r");
	gets(line);
	sscanf(line,"%f%f",&lenght,&breadth);
	area=(lenght*breadth);
	printf("\n\n Area = %f\n",area);
}
void calc_circle(void)
{
	float area,radius,pi=(3.14);
	char line[200];
	printf("\n\n Enter Radius:\n\r");
	gets (line);
	sscanf(line,"%f",&radius);
	area=(radius*radius*pi);
	printf("\n\n Area=%f \n",area);
}
void wait_for_user(void)
{
	char dummy[80];
	printf("\n\n Press Return to continue:");
	gets(dummy);
}
	
	
	
	