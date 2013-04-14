/*Evan O'Keeffe
  10324289
  question6 practical 10
  comments below
*/

#define true 1
#define false 0
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct
{
	int day;
	int month;
	int year;
}date;

typedef struct
{
	char name[80];
	char street[80];
	char city[80];
	int acct_no;
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	date lastpayment;	
}record;

record a;//record variable

FILE *fp,*fopen();
char who[20];		//used to find someone in the database

void change_record();
void add_to_record();
void wait_for_user();
void read_file();
void clear_screen();
void options();
void end_all();
void open_file(char* who);

int main()
{
	clear_screen();
	options();
	return 0;
}

void options()//give some options for the DB
{
	char dummy;
	int answer;
	
	printf("Welcome to database V1.0\r\n");
	printf("Please enter a number\r\n");
	printf("1.read database\r\n");
	printf("2.change database\r\n");
	printf("3.add to database\r\n");
	printf("4.quit\r\n");
	scanf("%d",&answer);
	dummy=getchar();
	
	if(answer==1){read_file();}
	if(answer==2){change_record();}
	if(answer==3){add_to_record();}
	if(answer==4){end_all();}
	
}

void end_all()//end the program cycle
{
	clear_screen();
	printf("Thank you for using my database V1.0\r\n");
	exit(0);
}

void read_file()//read the file user input by user input
{
	fp=fopen("1.dat","r");
	
	if(check_file(fp)==true)
	{
		while(fscanf(fp,"%s %s %s %d %c %f %f %f %d %d %d",a.name,a.street,a.city,&a.acct_no,&a.acct_type,&a.oldbalance,&a.newbalance,&a.payment,&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year)!=EOF)
		{
			printf("name: %s\nstreet: %s\ncity: %s\nacc_num: %d\nacct_type: %c\nob: %f\nnb: %f\npayment: %f\ndate: %d %d %d\r\n",a.name,a.street,a.city,a.acct_no,a.acct_type,a.oldbalance,a.newbalance,a.payment,a.lastpayment.day,a.lastpayment.month,a.lastpayment.year);
			printf("\n");
			wait_for_user();
		}
		fclose(fp);
		main();
	}
	if(check_file(fp)==false)
	{
		fclose(fp);
		printf("file not there1\r\n");
		exit(0);
	}
}

void clear_screen()//clear the screen
{
	int i;
	for(i=0;i<25;i++){printf("\n");}
}

void wait_for_user()//wait for user input
{
	char dummy[20];
	printf("press enter to continue\r\n");
	gets(dummy);
}

void change_record()//change something in the database
{

	int user,count=0;
	char dummy;
	char user_choice;
	
	printf("Do you know who you looking for?\r\n");
	printf("press Y to search for the name or N to see the DB\r\n");
	scanf("%c",&user_choice);
	dummy=getchar();
	if(user_choice=='Y'||user_choice=='y')
	{
		
		while(count<20){who[count]='\0';count++;}
		
		printf("Please enter the name of someone in the database, CASE IS SENSITIVE\r\n");
		scanf("%s",&who);
		//printf("who= %s\r\n",&who);
		printf("please enter a number for the piece of information you want to change\r\n");
		printf("Change the whole line\r\n");
		printf("1.update log \r\n");
		printf("2.exit \r\n");
		scanf("%d",&user);
		dummy=getchar();
		//printf("user=%d\r\n",user);
		if(user==1)
		{
			printf("who= %s\r\n",&who);
			open_file(who);
		}
		if(user==2){end_all();}
	}
	else{read_file();}
}

void open_file(char* who)
{
	int i=0,comparison=0,comparison1=0;
	int string_lenght=0;
	char dummy;
	
	string_lenght=strlen(who);
	printf("lenght =%d\r\n",string_lenght);
	fp=fopen("1.dat","rw");
	while(fscanf(fp,"%s %s %s %d %c %f %f %f %d %d %d",a.name,a.street,a.city,&a.acct_no,&a.acct_type,&a.oldbalance,&a.newbalance,&a.payment,&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year)!=EOF)
		{
			while(comparison1<string_lenght){if(who[comparison]==a.name[comparison]){comparison++;}comparison1++;}
			printf("who=%s and DB name = %s\r\n",who,a.name);
			if(strcmp(who,a.name)==0){break;}
			i++;
			string_lenght=0;
		}
		fclose(fp);
	printf("Name =%s\r\n",a.name);
	
	printf("Please enter the new address of the costumer\r\n");
	scanf("%s",a.street);
	dummy=getchar();
	
	printf("Please enter the new city of the costumer\r\n");
	scanf("%s",a.city);
	dummy=getchar();
	
	printf("Please enter the new account number of the costumer\r\n");
	scanf("%d",&a.acct_no);
	dummy=getchar();
	
	printf("Please enter the new account type of the costumer\r\n");
	scanf("%c",&a.acct_type);
	dummy=getchar();
	
	printf("Please enter the new old balance of the costumer(float)\r\n");
	scanf("%f",&a.oldbalance);
	dummy=getchar();
	
	printf("Please enter the new new balance of the costumer(float)\r\n");
	scanf("%f",&a.newbalance);
	dummy=getchar();
	
	printf("Please enter the new payment of the costumer(float)\r\n");
	scanf("%f",&a.payment);
	dummy=getchar();
	
	printf("Please enter the new date of last transaction of the costumer\r\n");
	printf("day/month/year in numbers please\r\n");
	scanf("%d/%d/%d",&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year);
	dummy=getchar();
	
	fp=fopen("1.dat","a");
	fprintf(fp,"\n%s %s %s %d %c %f %f %f %d %d %d",a.name,a.street,a.city,&a.acct_no,a.acct_type,&a.oldbalance,&a.newbalance,&a.payment,&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year);
	printf("update complete\r\n");
	fclose(fp);
	
	wait_for_user();
	main();
	
}

void add_to_record()//add to the record
{
	char dummy;

	printf("Please enter the name of the costumer\r\n");
	scanf("%s",a.name);
	dummy=getchar();
	
	printf("Please enter the address of the costumer\r\n");
	scanf("%s",a.street);
	dummy=getchar();
	
	printf("Please enter the city of the costumer\r\n");
	scanf("%s",a.city);
	dummy=getchar();
	
	printf("Please enter the account number of the costumer\r\n");
	scanf("%d",&a.acct_no);
	dummy=getchar();
	
	printf("Please enter the account number of the costumer\r\n");
	scanf("%c",&a.acct_type);
	dummy=getchar();
	
	printf("Please enter the old balance of the costumer(float)\r\n");
	scanf("%f",&a.oldbalance);
	dummy=getchar();
	
	printf("Please enter the new balance of the costumer(float)\r\n");
	scanf("%f",&a.newbalance);
	dummy=getchar();
	
	printf("Please enter the payment of the costumer(float)\r\n");
	scanf("%f",&a.payment);
	dummy=getchar();
	
	printf("Please enter the date of last transaction of the costumer\r\n");
	printf("day/month/year in numbers please\r\n");
	scanf("%d/%d/%d",&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year);
	dummy=getchar();
	
	fp=fopen("1.dat","a");
	fprintf(fp,"\n%s %s %s %d %c %f %f %f %d %d %d",a.name,a.street,a.city,&a.acct_no,a.acct_type,&a.oldbalance,&a.newbalance,&a.payment,&a.lastpayment.day,&a.lastpayment.month,&a.lastpayment.year);
	printf("update complete\r\n");
	fclose(fp);
	
	wait_for_user();
	main();
}

int check_file(FILE *fp)//check if file exists
{
	if(fp==NULL){return false;}
	if(fp!=NULL){return true;}
}