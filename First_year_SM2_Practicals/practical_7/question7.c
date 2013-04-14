/*EvanO'Keeffe
  10324289
  practical7 question7
*/
#include<stdio.h>
#include<stdlib.h>

//sadly this version i didn't have enough time to get all functions working with the database

void get_number();//search for number
void get_part_name();//search for name
void add_part();//add something to the database
void read_out();//read out the databases 1 at a time
void wait_for_user();//wait for the user to input something
void change_quantity();//change quantity of a certain product
int check_file(FILE *fp);//check if file exists

struct database
{
	char* name;
	int product_number;
	int quantity;
};//sequentially will read the name ,product number and quantity of each of the fieds in this structured array

struct database products[50];

void main()
{
	char answer[100];
	
	
	printf("Enter part to search for the name of the part\r\n\n");
	printf("Enter number to search for the number of the part\r\n\n");
	printf("enter change if you want to change the quantity of a current product\r\n\n");
	printf("Enter add part to add an item to the database\r\n\n");
	printf("If you want to read the whole database then please enter read\n\r\n");
	printf("If you want to exit, enter quit\r\n\n");
	gets(answer);
	
	if(answer[0]=='N'||answer[0]=='n'){get_number();}
	else if(answer[0]=='P'||answer[0]=='p'){get_part_name();}
	else if(answer[0]=='C'||answer[0]=='c'){change_quantity();}
	else if(answer[0]=='A'||answer[0]=='a'){add_part();}
	else if(answer[0]=='R'||answer[0]=='r'){read_out();}
	else if(answer[0]=='Q'||answer[0]=='q'){exit(0);}
	else
		{
			printf("Answer was none of the statements , thank you for using this\r\n");
		}
	

}
void get_number()
{
	int c,i=0;
	int productN[100],quantityN[100];
	char name[100],create[100],character;
	char user[20];
	printf("Please enter a number\r\n");
	scanf("%d",&c);
	
	FILE *fopen(),*fp;
	fp=fopen("database.txt","r");
	//printf("Here 1\r\n");
	if(check_file(fp)==0){printf("file doesn't exists\r\n");}
	else
	{	
		fp=fopen("database.txt","r");
		i=0;
		while(fscanf(fp,"%s %d %d",name,&productN[i],&quantityN[i])!=EOF)//scan all the lines  until the end
		{
			if(productN[i]==c){printf("\nproduct=%s number=%d and quantity=%d\r\n",name,productN[i],quantityN[i]);}
			i++;
			/*printf("i=%d and counter=%d\r\n",i,counter);*/
		}
		
		i=0;
	}
	fclose(fp);
}
void get_part_name()
{
	char post[10];
	int i=0;
	int productN[100],quantityN[100];
	char name[100],create[100],character;
	char user[20];
	printf("Please enter the name of what your looking for\r\n");
	scanf("%s",post);
	
	FILE *fopen(),*fp;
	fp=fopen("database.txt","r");
	if(check_file(fp)==0){printf("file doesn't exists\r\n");}
	else
	{	
		fp=fopen("database.txt","r");
		i=0;
		while(fscanf(fp,"%s %d %d",name,&productN[i],&quantityN[i])!=EOF)//scan all the lines  until the end
		{
			if(strcmp(name,post)==0){printf("\nproduct=%s number=%d and quantity=%d\r\n",name,productN[i],quantityN[i]);}
			i++;
			/*printf("i=%d and counter=%d\r\n",i,counter);*/
		}
		
		i=0;
	}
	fclose(fp);
}
void add_part()
{
	char add[100];
	char reply[100];
	int productN[100],quantityN[100];
	char name[100],create[100],character;
	char user[20];
	int adda,i=0,amount;
	
	FILE *fopen(),*fp;
	fp=fopen("database.txt","r");
	if(check_file(fp)==0){printf("file doesn't exists\r\n");}
	
	else
	{	
		
		fclose(fp);
		printf("Please enter the name of the part your adding\r\n");
		scanf("%s",add);
		//printf("You entered %s\r\n",add);
		fp=fopen("database.txt","r");
		i=0;
		while(fscanf(fp,"%s %d %d",name,&productN[i],&quantityN[i])!=EOF)//scan all the lines  until the end
		{
			if(strcmp(name,add)==0){printf("\nproduct=%s number=%d and quantity=%d already exists\r\n",name,productN[i],quantityN[i]);exit(0);}
			i++;
			/*printf("i=%d and counter=%d\r\n",i,counter);*/
		}
		fclose(fp);
		i=0;
		
		//printf("place 1\r\n");
		printf("Please enter the product number \r\n");
		scanf("%d",&adda);
		
		fp=fopen("database.txt","r");
		i=0;
		while(fscanf(fp,"%s %d %d",name,&productN[i],&quantityN[i])!=EOF)//scan all the lines  until the end
		{
			if(productN[i]==adda){printf("\nproduct=%s number=%d and quantity=%d already exists\r\n",name,productN[i],quantityN[i]);}
			i++;
			/*printf("i=%d and counter=%d\r\n",i,counter);*/
		}
		fclose(fp);
		i=0;
		
		printf("How much will be in the WareHouse \r\n");
		scanf("%d",&amount);
		fclose(fp);

		printf("So you have a product name as: %s\r\n",add);
		printf("product number as: %d\r\n",adda);
		printf("and there is: %d  \r\n",amount);
		printf("Is this right Y/N\r\n");
		scanf("%s",reply);
		
		if(reply[0]=='N'||reply[0]=='n'){printf("Please enter your values again\r\n");wait_for_user();main();}
		else 
			{
				fp=fopen("database.txt","a");
				fprintf(fp,"%s %d %d\r\n",add,adda,amount);
				printf("Database updated,thank you\r\n");
				fclose(fp);
				wait_for_user();
			}
	}
	
}
void change_quantity()
{
	int c,i=0,k;
	int productN[100],quantityN[100];
	char name[100],create[100],character;
	char user[20];
	printf("Please enter a number\r\n");
	scanf("%d",&c);
	
	FILE *fopen(),*fp;
	fp=fopen("database.txt","r");
	//printf("Here 1\r\n");
	if(check_file(fp)==0){printf("file doesn't exists\r\n");}
	else
	{	
		fp=fopen("database.txt","rw");
		i=0;
		while(fscanf(fp,"%s %d %d",name,&productN[i],&quantityN[i])!=EOF)//scan all the lines  until the end
		{
			if(productN[i]==c)
			{
				printf("\nproduct=%s number=%d and quantity=%d \r\n",name,productN[i],quantityN[i]);
				printf("Please enter the new quantity value\r\n");
				scanf("%d",&k);
				quantityN[i]=k;
				fprintf(fp,"%s %d %d",name,productN[i],quantityN[i]);
				printf("Changed to :\r\n");
				printf("\nproduct=%s number=%d and quantity=%d \r\n",name,productN[i],quantityN[i]);
			}
			i++;
		}
		i=0;
	}
	fclose(fp);
}
void read_out()
{
	int k=0;
	FILE *fopen(),*fp;
	int count;
	fp=fopen("database.txt","r");

	if(check_file(fp)==0){printf("Problem reading the file SLOTS_BEST_productN.txt, have you created it yet?\r\n");}
	else
		{
			count=getc(fp);
			while(count!=EOF)
			{
				count=getc(fp);
				putchar(count);
			}
		}//open the file and put the characters onto the screen
	fclose(fp);
	wait_for_user();
}
void wait_for_user()
{
	char dummy[10];
	printf("\nPlease press a letter then enter\r\n");
	scanf("%s",dummy);
}
int check_file(FILE *fp)
{
	if(fp==NULL){return 0;}
	if(fp!=NULL){return 1;}
}