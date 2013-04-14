/*Evan O'Keeffe
  10324289
  practical 13 question2
  completly restructured the whole thing this time using a linked list data structure and data array and sorting arrray,
  the list structure is refreshed every time it enters a function , this is to keep the program going as long as possible without a reboot of
  it.
  Each function and sub-function is explained and should be fairly easy to read.
  The program so far can update by changing any info of a person and also delete them from the system in total.
  When adding or deleting information in the program , the file will be resorted by id number, 
  The levy value is calculated during the print out , therefore i didn't add an actual label for it , it is calculated for the net income which is
  labelled n_inc
  
  hope you enjoy the program so far
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//My Macro's
#define TRUE 1
#define FALSE 0
#define HOUR 366
#define ERROR printf("Error at %d in %s\r\n",__LINE__,__FILE__);
#define LINEN printf("line=%d\r\n",__LINE__);
#define NEMP  printf("Employee isn't in the DB\r\n");
#define NF printf("File employee.dat is either missing or is unavaible at the moment\r\n");

struct DATA
{
	int id;
	char ln[80];
	char fn[80];
	double wh;
	double pay;
	int tax;
	double g_inc;
	double n_inc;
	double Levy=(g_inc/100);
};

struct DATA DB[200];//record variable
struct DATA sort[200];
struct DATA DEL[10];//used for taking out a single name from the file and not reprinting the file with that name
struct DATA A;

FILE *fp,*fopen();						

//used for deleting a name from the DB
char answer1[100];	//get answer1
char answer2[100];	//get answer2
char dummy;			//dummy character
double ltax,htax,deducted;			//used for calculating the tax for the person when they add to the database,less chance of human error			
int c,i,count,counter,answer,n,k;	//counters vor various function

int check_file(FILE *fp);	//check if the file exists
void change_record();		//reads in the file, takes the string , asks the user if the current info is good , reprints the whole file
void change_file(int n);	//changes the persons info and reprints entire file
void add_to_record();		//simple add to record function
void search_file_ini();		//search initialiser
void search_file(int n);	//search file functions
void delete_record();		//works by raeding in all of the file , then it will print everything but that name's info back to the file
void info();				//new function that shows the operating system , time , DB version number and other pieces
void sort_file_ini();		//get the sorting option
void sort_file(int n);		//sort the file by the users option from sort_file_ini();
void wait_for_user();
void clear_screen();
void options();
void end_all();


int main()
{
	options();
	return 0;
}

void options()//give some options for the DB
{
	clear_screen();
	char dummy;
	int answer;
	
	printf("Welcome to Employee database V1.0\r\n");
	printf("Please enter a number\r\n");
	printf("1.read database by a sorted pattern\r\n");
	printf("2.search for a person in the database\r\n");
	printf("3.change a persons information in the database\r\n");
	printf("4.add a person to the database\r\n");
	printf("5.delete name from the database\r\n");
	printf("6.quit the program\r\n");
	scanf("%d",&answer);
	dummy=getchar();
	switch(answer)
	{
		case 1:{sort_file_ini();break;}
		case 2:{search_file_ini();break;}
		case 3:{change_record();break;}
		case 4:{add_to_record();break;}
		case 5:{delete_record();break;}
		case 6:{end_all();break;}
		case 7:{info();break;}
		default:{options();break;}
	}
	
}

void info()
{
	printf("file=%s\r\n",__FILE__);
	printf("line=%d\r\n",__LINE__);
	printf("date=%s\r\n",__DATE__);
	printf("time=%s\r\n",__TIME__);
	printf("C=%d\r\n",__STDC__);
	wait_for_user();
	options();
}

void clear_screen()//clear the screen
{
	i=0;
	for(i=0;i<25;i++){printf("\n");}
}

void wait_for_user()//wait for user input
{
	dummy='\0';
	printf("\npress enter to continue\r\n");
	dummy=getchar();
	dummy=getchar();
}

void end_all()//end the program cycle
{
	clear_screen();
	printf("Thank you for using database V1.0\r\n");
	exit(0);
}

void search_file_ini()//search the file
{
	fp=fopen("employee.dat","r");
	
	int ST=0;	//ST stands for search type
	c=0;
	count=0;
	
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		printf("Please input a search code\r\n");
		printf("1.by first name\r\n");
		printf("2.by last name\r\n");
		printf("3.By ID number\r\n");
		printf("4.By working hours\r\n");
		printf("5.By tax rate\r\n");
		printf("6.By Income(net)\r\n");
		printf("7.By payment\r\n");
		printf("8.by line\r\n");
		printf("9.back to main menu\r\n");
		scanf("%d",&ST);
		
		switch(ST)
		{
			case 1:{search_file(1);break;}
			case 2:{search_file(2);break;}
			case 3:{search_file(3);break;}
			case 4:{search_file(4);break;}
			case 5:{search_file(5);break;}
			case 6:{search_file(6);break;}
			case 7:{search_file(7);break;}
			case 8:{search_file(8);break;}
			case 9:{options();break;}
			default:{search_file_ini();break;}
		}
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
	
}

void search_file(int n)
{
	c=0;i=0;
	count=0;
	fp=fopen("employee.dat","r");
	c=getc(fp);
	while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
	fclose(fp);
	fp=fopen("employee.dat","r");	
	while(i<=count)
	{
		fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
		i++;
	}
	fclose(fp);
	//LINEN
	
	switch(n)
	{
		case 1:
		{
			printf("Please enter a first name\r\n");
			scanf("%s",&A.fn);
			for(i=0;i<=count;i++)
			{
				if(strcmp(A.fn,DB[i].fn)==0)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==(count+1)){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			break;
		}
		
		case 2:
		{
			printf("Please enter a last name\r\n");
			scanf("%s",&A.ln);
			for(i=0;i<=count;i++)
			{
				if(strcmp(A.ln,DB[i].ln)==0)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==(count+1)){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			break;
		}
		
		case 3:
		{
			printf("Please enter the ID\r\n");
			scanf("%d",&A.id);
			for(i=0;i<=count;i++)
			{
				if(A.id==DB[i].id)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==count){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			break;
		}
		
		case 4:
		{
			printf("Please enter the working hours\r\n");
			scanf("%lf",&A.wh);
			for(i=0;i<=count;i++)
			{
				if(A.wh==DB[i].wh)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==count){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			break;
		}
		
		case 5:
		{
			printf("Please enter the tax\r\n");
			scanf("%d",&A.tax);
			for(i=0;i<=count;i++)
			{
				if(A.tax==DB[i].tax)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==count){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}			
			break;
		}
		
		case 6:
		{
			printf("Please enter an income\r\n");
			scanf("%lf",&A.n_inc);
			for(i=0;i<=count;i++)
			{
				if(A.n_inc==DB[i].n_inc)
				{
					printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
					printf("Is this the person you are looking for?\r\n");
					printf("Y or N\r\n");
					scanf("%s",&answer1);
					if(answer1[0]=='y'||answer1[0]=='Y'){break;}
				}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==count){NEMP}
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			break;
		}
		
		case 7:
		{
		printf("Please enter a payment\r\n");
		scanf("%lf",&A.pay);
		for(i=0;i<=count;i++)	
		{
			if(A.pay==DB[i].pay)
			{
				printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
				printf("Is this the person you are looking for?\r\n");
				printf("Y or N\r\n");
				scanf("%s",&answer1);
				if(answer1[0]=='y'||answer1[0]=='Y'){break;}
			}
		}
		printf("i=%d,%d=count\r\n",i,count);
		if(i==count){NEMP}
		else
			{
			wait_for_user();
			printf("Would you like to search again?\r\n");
			printf("Y to search again , N to go back to main menu\r\n");
			scanf("%s",&answer1);
			if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
			else
				{options();}
			}
		break;
		}
		
		default:
		{
			for(i=0;i<=count;i++)
			{
				printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
				printf("Is this the person you are looking for?\r\n");
				printf("Y or N\r\n");
				scanf("%s",&answer1);
				if(answer1[0]=='y'||answer1[0]=='Y'){break;}
			}
			printf("i=%d,%d=count\r\n",i,count);
			if(i==count){NEMP}
			else
			{
				wait_for_user();
				printf("Would you like to search again?\r\n");
				printf("Y to search again , N to go back to main menu\r\n");
				scanf("%s",&answer1);
				if(answer1[0]=='y'||answer1[0]=='Y'){search_file_ini();}
				else
					{options();}
			}
			break;
		}
		
	}
	wait_for_user();
	options();
}

void change_record()//change something in the database
{
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0;i=0;
		count=0;
		fp=fopen("employee.dat","r");
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		fclose(fp);
		fp=fopen("employee.dat","r");	
		while(i<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
			i++;
		}
		fclose(fp);
		//LINEN
		
		printf("Please input a search code\r\n");
		printf("1.by first name\r\n");
		printf("2.by last name\r\n");
		printf("3.By ID number\r\n");
		scanf("%d",&answer);
		
		switch(answer)
		{
			case 1:
			{
				printf("Please enter a first name\r\n");
				scanf("%s",&A.fn);
				for(i=0;i<=count;i++)
				{
					if(strcmp(A.fn,DB[i].fn)==0)
					{
						printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
						printf("Is this the person you are looking for?\r\n");
						printf("Y or N\r\n");
						scanf("%s",&answer1);
						if(answer1[0]=='y'||answer1[0]=='Y'){break;}
					}
				}
				//printf("i=%d,%d=count\r\n",i,count);
				if(i==(count+1)){NEMP}
				else
				{
					wait_for_user();
					printf("Are you sure you want to change this person?\r\n");
					printf("Y to change , N to go back to main menu\r\n");
					scanf("%s",&answer2);
					if(answer2[0]=='y'||answer2[0]=='Y'){change_file(i);}
					else
						{options();}
				}
				break;
			}
			
			case 2:
			{
				printf("Please enter a last name\r\n");
				scanf("%s",&A.ln);
				for(i=0;i<=count;i++)
				{
					if(strcmp(A.ln,DB[i].ln)==0)
					{
						printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
						printf("Is this the person you are looking for?\r\n");
						printf("Y or N\r\n");
						scanf("%s",&answer2);
						if(answer2[0]=='y'||answer2[0]=='Y'){break;}
					}
				}
				//printf("i=%d,%d=count\r\n",i,count);
				if(i==(count+1)){NEMP}
				else
				{
					wait_for_user();
					printf("Are you sure you want to change this person?\r\n");
					printf("Y to change , N to go back to main menu\r\n");
					scanf("%s",&answer2);
					if(answer2[0]=='y'||answer2[0]=='Y'){change_file(i);}
					else
						{options();}
				}
				break;
			}
			
			default:
			{
				printf("Please enter the ID\r\n");
				scanf("%d",&A.id);
				for(i=0;i<=count;i++)
				{
					if(A.id==DB[i].id)
					{
						printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
						printf("Is this the person you are looking for?\r\n");
						printf("Y or N\r\n");
						scanf("%s",&answer1);
						if(answer1[0]=='y'||answer1[0]=='Y'){break;}
					}
				}
				printf("i=%d,%d=count\r\n",i,count);
				if(i==count){NEMP}
				else
				{
					wait_for_user();
					printf("Are you sure you want to change this person?\r\n");
					printf("Y to change , N to go back to main menu\r\n");
					scanf("%s",&answer2);
					if(answer2[0]=='y'||answer2[0]=='Y'){change_file(i);}
					else
						{options();}
				}
				break;
			}
			
		}
		
		
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
}

void change_file(int n)
{
	LINEN
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0,k=0;
		count=0;
		fp=fopen("employee.dat","r");
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		fclose(fp);
		fp=fopen("employee.dat","r");
		//LINEN
		while(k<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[k].id,&DB[k].ln,&DB[k].fn,&DB[k].wh,&DB[k].pay,&DB[k].tax,&DB[k].g_inc,&DB[k].n_inc);
			//printf("%d %s %s %lf %lf %d %lf %lf",DB[k].id,DB[k].ln,DB[k].fn,DB[k].wh,DB[k].pay,DB[k].tax,DB[k].g_inc,DB[k].n_inc);
			k++;
		}
		fclose(fp);
		//LINEN
		i=n;
		printf("i=%d\r\n",i);
		for(k=0;k<=200;k++)
		{
			if(k==i)
			{
			printf("ID:%d\tLname:%s\tFname:%s\nHours:%lf\tPay:%lf\nTax:%d\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
			break;
			}
		}
		printf("ID:%d\r\n",DB[i].id);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new id\r\n");
			scanf("%d",&DB[i].id);
		}
		printf("Last name:\r\n",DB[i].ln);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new last name\r\n");
			scanf("%s",&DB[i].ln);
		}
		printf("first name:\r\n",DB[i].fn);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new first name\r\n");
			scanf("%s",&DB[i].fn);
		}
		printf("working hours:\r\n",DB[i].wh);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new working hours\r\n");
			scanf("%lf",&DB[i].wh);
		}
		
		printf("Pay:\r\n",DB[i].pay);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new pay\r\n");
			scanf("%lf",&DB[i].pay);
		}
		
		printf("Tax:\r\n",DB[i].tax);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new tax\r\n");
			scanf("%d",&DB[i].tax);
		}
		
		printf("Gross Income\r\n",DB[i].g_inc);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new id\r\n");
			scanf("%lf",&DB[i].g_inc);
		}
		
		printf("Net Income\r\n",DB[i].n_inc);
		printf("Enter Y to continue or N to change\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='n'||answer1[0]=='N')
		{
			printf("Please enter a new id\r\n");
			scanf("%lf",&DB[i].n_inc);
		}
		
		wait_for_user();
		printf("ID:%d\r\n",DB[i].id);
		printf("first name:\r\n",DB[i].fn);
		printf("Last name:\r\n",DB[i].ln);
		printf("working hours:\r\n",DB[i].wh);
		printf("Pay:\r\n",DB[i].pay);
		printf("Tax:\r\n",DB[i].tax);
		printf("Gross Income\r\n",DB[i].g_inc);
		printf("Net Income\r\n",DB[i].n_inc);
		printf("Is this right?\r\n");
		scanf("%s",&answer1);
		
		if(answer1[0]=='y'||answer1[0]=='Y')
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].id>DB[i+1].id)
					{
						//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
						//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
					}
					//printf("DB[%d].id=%d\r\n",i,DB[i].id);
				}
			}
			
			fp=fopen("employee.dat","w");
			for(i=0;i<=200;i++)
			{
				if(DB[i].id!=0){fprintf(fp,"%d %s %s %lf %lf %d %lf %lf\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			}
			fclose(fp);
			printf("%d %s %s was updated in the system\r\n",DEL[n].id,DEL[n].ln,DEL[n].fn);
			printf("System updated\r\n");
			wait_for_user();
			options();
		}
		else
			{printf("Begining procedure again\r\n");wait_for_user();change_record();}
		
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
		
}

void sort_file_ini()
{
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0;i=0;
		count=0;
		fp=fopen("employee.dat","r");
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		fclose(fp);
		fp=fopen("employee.dat","r");	
		while(i<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
			i++;
		}
		//LINEN
		i=0;
		/*
		while(i<=count)
		{
			printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
			wait_for_user();
			i++;
		}
		*/
		fclose(fp);
		printf("Please input a sort code\r\n");
		printf("1.by first name\r\n");
		printf("2.by last name\r\n");
		printf("3.By ID number\r\n");
		printf("4.By working hours\r\n");
		printf("5.By tax rate\r\n");
		printf("6.By Income(net)\r\n");
		printf("7.By payment\r\n");
		printf("8.return to main menu\r\n");
		scanf("%d",&answer);
		switch(answer)
		{
			case 1:{sort_file(1); break;}
			
			case 2:{sort_file(2); break;}
			
			case 3:{sort_file(3); break;}
			
			case 4:{sort_file(4); break;}
			
			case 5:{sort_file(5); break;}
			
			case 6:{sort_file(6); break;}
			
			case 7:{sort_file(7); break;}
			
			case 8:{options();break;}
			
			default:{sort_file_ini(); break;}
		}
		
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
}

void sort_file(int n)
{
	char temp1,temp2;
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0;i=0;
		count=0;
		fp=fopen("employee.dat","r");
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		//printf("Count=%d\r\n",count);
		fclose(fp);
		fp=fopen("employee.dat","r");	
		while(i<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
			i++;
		}
		
		
		if(n==1)//bubble sort the first names
		{	
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=100;i++)
				{
					temp1 = DB[i].fn[0];
					temp2 = DB[i+1].fn[0];
					if(temp1>temp2)
					{
						//printf("DB[%d]=%s\r\n",i,DB[k].fn);
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1]= sort[i];
						//printf("DB[%d]=%s\r\n",i,DB[k].fn);
					}
				}
			}
			
			//LINEN
			
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{printf("Fname:%s\nLname:%s\tID:%d\nHours:%lf\tPay:%lf\nTax:%d\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].fn,DB[i].ln,DB[i].id,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			}
			wait_for_user();
			options();
		}
		
		if(n==2)//bubble sort the last names
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=100;i++)
				{
					if(DB[i].ln[0]>DB[i+1].ln[0])
					{
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
					}
				//printf("DB[%d]=%c\r\n",i,DB[k].fn[0]);
				}
			}
			//LINEN
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{printf("Lname:%s\nFname:%s\tID:%d\nHours:%lf\tPay:%lf\nTax:%d\nG-inc:%lf\tNet-inc%lf\r\n\n",DB[i].ln,DB[i].fn,DB[i].id,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			}
			wait_for_user();
			options();
		}
		
		if(n==3)//bubble sort the ID numbers
		{
			counter=0;
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].id>DB[i+1].id)
					{
						//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
						//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
					}
				//printf("DB[%d].id=%d\r\n",i,DB[i].id);
				}
			}
			LINEN
			
			for(i=0;i<=200;i++)
			{
				if(DB[i].id!=0)
				{printf("ID:%d\tLname:%s\tFname:%s\nHours:%lf\tPay:%lf\nTax:%d\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			}
			wait_for_user();
			options();
			
		}
		
		if(n==4)//bubble sort the working hours , first number after name
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].wh>DB[i+1].wh)
					{
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
					}
				}
			}
			
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{
					printf("Hours:%lf\nLname:%s\tFname:%s\tID:%d\nPay:%lf\tTax:%d\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].wh,DB[i].ln,DB[i].fn,DB[i].id,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
				}
			}
			wait_for_user();
			options();
		}
		
		if(n==5)//bubble sort the tax , second number after the first name
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].tax>DB[i+1].tax)
					{
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
					}
				//printf("DB[%d].id=%lf\r\n",i,DB[i].tax);
				}
			}
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{printf("Tax:%d\nLname:%s\tFname:%s\tID:%d\nHours:%lf\tPay:%lf\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].tax,DB[i].ln,DB[i].fn,DB[i].id,DB[i].wh,DB[i].pay,DB[i].g_inc,DB[i].n_inc);}
			}
			wait_for_user();
			options();
			
		}
		
		if(n==6)//bubble sort the net income , last number
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].n_inc==i)
					{
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
					}
				//printf("DB[%d].id=%lf\r\n",i,DB[i].n_inc);
				}
			}
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{printf("%lf %d %s %s %lf %lf %d %lf \r\n\n",DB[i].n_inc,DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc);}
			}
			wait_for_user();
			options();
		}
		
		if(n==7)//bubble sort the pay per hour
		{
			for(k=0;k<=count;k++)
			{
				for(i=0;i<=count;i++)
				{
					if(DB[i].pay==i)
					{
						sort[i] = DB[i];
						DB[i] = DB[i+1];
						DB[i+1] = sort[i];
						
					}
				//printf("DB[%d].id=%lf\r\n",i,DB[i].pay);
				}
			}
			for(i=0;i<200;i++)
			{
				if(DB[i].id!=0)
				{printf("Pay%lf\nID:%d\tLname:%s\tFname:%s\nHours:%lf\nTax:%d\nG-inc:%lf\tN-inc:%lf\r\n\n",DB[i].pay,DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			}
			wait_for_user();
			options();
		}
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
}

void add_to_record()//add to the record
{
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0;i=0;
		count=0;
		fp=fopen("employee.dat","r");
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		fclose(fp);
		fp=fopen("employee.dat","r");	
		while(i<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
			i++;
		}
		//LINEN
		i=0;
		/*
		while(i<=count)
		{
			printf("\nID:%d\n Lname:%s\n fname:%s\n Hours:%lf\n pay:%lf\n tax:%d\n G-inc:%lf\n N-inc:%lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
			wait_for_user();
			i++;
		}
		*/
		fclose(fp);
		
		A.id=0;
		printf("Please enter the employee ID\r\n");
		scanf("%d",&A.id);
		
		while(i<=count)
		{
			//printf("A.id=%d,ID=%d\r\n",A.id,a.ident);
			if(A.id==DB[i].id)
			{
				printf("Employee ID already exists,please try again\r\n");
				add_to_record();
			}
			i++;
		}
		
		printf("Please enter the first name\r\n");
		scanf("%s",&A.fn);
		
		printf("Please enter the last name\r\n");
		scanf("%s",&A.ln);
		
		for(i=0;i<80;i++)
		{
			A.fn[i]=tolower(A.fn[i]);
			A.ln[i]=tolower(A.ln[i]);
		}
		for(i=0;i<=count;i++)
		{
			//printf("A.id=%d,ID=%d\r\n",A.id,a.ident);
			if(strcmp(A.fn,DB[i].fn)==0&&strcmp(A.ln,DB[i].ln)==0)
			{
				printf("Employee already exists,please try again\r\n");
				add_to_record();
			}
		}
		printf("Please enter the working hours\r\n");
		scanf("%lf",&A.wh);
		
		printf("Please enter the pay rate\r\n");
		scanf("%lf",&A.pay);
		clear_screen();
		
		printf("employee ID     =%d\r\n",A.id);
		printf("A.fn name		=%s\r\n",A.fn);
		printf("A.ln name		=%s\r\n",A.ln);
		printf("working hours		=%lf\r\n",A.wh);
		printf("pay_rate		=%lf\r\n",A.pay);
		A.g_inc = A.pay * HOUR;
		if(A.g_inc<36400){A.tax=20;}
		if(A.g_inc>36400){A.tax=41;}
		printf("tax 			=%lf\r\n",A.tax);
		if(A.g_inc<36400){ltax=A.g_inc/A.tax;htax=0;}
		if(A.g_inc>36400){ltax=(A.g_inc+36400)/20;htax=(A.g_inc-36400)/41;}
			
		deducted=(ltax+htax);
		A.n_inc=A.g_inc-deducted;
		printf("gross income 		=%lf\r\n",A.g_inc);
		printf("net income		=%lf\r\n",A.n_inc);
		
		printf("Is this information correct?\r\n");
		printf("Y or N\r\n");
		scanf("%s",&answer1);
		if(answer1[0]=='y'||answer1[0]=='Y')
		{
			fopen("employee.dat","a");
			fprintf(fp,"\r%d %s %s %.3lf %.3lf %d %.3lf %.3lf\r\n",A.id,A.ln,A.fn,A.wh,A.pay,A.tax,A.g_inc,A.n_inc);
			printf("update complete\r\n");
			fflush(stdin);
			fclose(fp);
			wait_for_user();
			options();
		}
		else
		{fclose(fp);add_to_record();}
		
	}
	if(check_file(fp)==FALSE)
	{
		NF
		fclose(fp);
		wait_for_user();
		options();
	}
}

void delete_record()//delete the employee from the DB
{
	fp=fopen("employee.dat","r");
	if(check_file(fp)==TRUE)
	{
		fclose(fp);
		c=0;i=0;
		count=0;
		c=getc(fp);
		while(c!=EOF){if(c=='\n'){count++;}c=getc(fp);}
		fclose(fp);
		fp=fopen("employee.dat","r");	
		while(i<=count)
		{
			fscanf(fp,"%d %s %s %lf %lf %d %lf %lf",&DB[i].id,&DB[i].ln,&DB[i].fn,&DB[i].wh,&DB[i].pay,&DB[i].tax,&DB[i].g_inc,&DB[i].n_inc);
			i++;
		}
		//LINEN
		i=0;
		while(i<=count)
		{
			printf("%d %s %s %lf %lf %d %lf %lf\r\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);
			//wait_for_user();
			i++;
		}
		fclose(fp);
		
		printf("Please enter the id number of the employee\r\n");
		scanf("%d",&A.id);
		
		for(i=0;i<count;i++){if(DB[i].id==A.id){break;}}
		if(i==count)
		{
			NEMP
			wait_for_user();
			options();
		}
		for(k=0;k<=count;k++)
		{
			for(i=0;i<=count;i++)
			{
				if(DB[i].id>DB[i+1].id)
				{
					//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
					sort[i] = DB[i];
					DB[i] = DB[i+1];
					DB[i+1] = sort[i];
					//printf("DB[%d].id=%d,DB[%d]=%d\r\n",i,DB[i].id,(i+1),DB[i+1].id);
				}
			//printf("DB[%d].id=%d\r\n",i,DB[i].id);
			}
		}
		fp=fopen("employee.dat","w");
		for(i=0;i<=200;i++)
		{
			if(DB[i].id!=A.id&&DB[i].id!=0){fprintf(fp,"%d %s %s %lf %lf %d %lf %lf\n",DB[i].id,DB[i].ln,DB[i].fn,DB[i].wh,DB[i].pay,DB[i].tax,DB[i].g_inc,DB[i].n_inc);}
			if(DB[i].id==A.id){DEL[i]=DB[i];c=i;}
		}
		fclose(fp);
		printf("%d %s %s was deleted from the system\r\n",DEL[c].id,DEL[c].ln,DEL[c].fn);
		printf("System updated\r\n");
		wait_for_user();
		options();
	}
	if(check_file(fp)==FALSE)
	{
		NF
		wait_for_user();
		main();
	}
}

int check_file(FILE *fp)//check if file exists
{
	if(fp!=NULL){return TRUE;}
	if(fp==NULL){return FALSE;}
}