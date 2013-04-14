/*EvanO'Keeffe
  10324289
  practical7 question7
  this is the version that works but the database cannot be updated, but the user can search by name or number
*/
#include<stdio.h>
#include<stdlib.h>

void get_number();//search for number
void get_part_name();//search for name
void add_part();//add something to the database
void read_out();//read out the databases 1 at a time
void wait_for_user();//wait for the user to input something

struct database
{
	char* name;
	int product_number;
	int quantity;
};//sequentially will read the name ,product number and quantity of each of the fieds in this structured array

const struct database product_code1[]=
{
	{"lcd",1,15},
	{"oled",2,24},
	{"led",3,54},
	{"wxvga",4,3482},
	{"vga",5,43},
	{"xvga",6,321},
	{"amoled",7,32},
	{"cpu",8,34},
	{"gpu",9,5263},
	{"fpu",10,5236564},
	{"alu",11,234},
	{"ppu",12,562},
	{"sound board",13,235},
	{"graphics card",14,123},
	{"controller",15,1324},
	{"ps3",16,3124},
	{"xbox360",17,5},
	{"iphone",18,23},
	{"psp",19,78},
	{"G1",20,76}
};
const struct database product_code2[]=
{
	{"Hero",21,56},
	{"Legend",22,554},
	{"DesireZ",23,45},
	{"Windows7",24,42},
	{"Desire",25,36},
	{"Smart",26,46},
	{"Nexus one",27,897},
	{"Tattoo",28,8768},
	{"Touch2",29,87987},
	{"Magic",30,8768},
	{"Snap",31,75865},
	{"Shift",32,6756},
	{"S620",33,5433},
	{"Advantage",34,3562},
	{"Wildfire",35,2345},
	{"HD7",36,1324},
	{"Gratia",37,1324},
	{"Siemens",38,3434143},
	{"Sony Ericcson",39,4443},
	{"Nokia",40,4543543}
};

void main()
{
	char answer[100];
	
	
	printf("Enter part to search for the name of the part\r\n\n");
	printf("Enter number to search for the number of the part\r\n\n");
	printf("Enter add part to add an item to the database\r\n\n");
	printf("If you want to read the whole database then please enter read\n\r\n");
	printf("If you want to exit, enter quit\r\n\n");
	gets(answer);
	
	if(answer[0]=='N'||answer[0]=='n'){get_number();}
	else if(answer[0]=='P'||answer[0]=='p'){get_part_name();}
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
	printf("Please enter a number\r\n");
	scanf("%d",&c);
	while(i<60)
	{
		if(product_code1[i].product_number==c){printf("%s is number %d and there is %d in the warehouse\r\n",product_code1[i]);break;}
		if(product_code2[i].product_number==c){printf("%s is number %d and there is %d in the warehouse\r\n",product_code2[i]);break;}
		else
		 {i++;}
	}
	if(i==60){printf("Sorry but your part number isn't in the database\r\n");}

}
void get_part_name()
{
	char post[10];
	int i=0;
	printf("Please enter the name of what your looking for\r\n");
	scanf("%s",post);
	//printf("Here 1\r\n");
	//printf("%s\r\n",post);
	while(i<40)
	{
		if(strcmp(product_code1[i].name,post)==0){printf("%s is number %d and there is %d in the warehouse\r\n",product_code1[i]);i=40;}
		if(strcmp(product_code2[i].name,post)==0){printf("%s is number %d and there is %d in the warehouse\r\n",product_code2[i]);i=40;}
		i++;
	}
	if(i==40){printf("Sorry but your part name isn't in the database\r\n");}
}
void add_part()
{
	char add[10];
	char reply[100];
	int adda,i=0,amount;
	
	printf("Please enter the name of the part your adding\r\n");
	scanf("%s",add);
	//printf("You entered %s\r\n",add);
	while(i<20)
	{
		if(strcmp(product_code1[i].name,add)==0){printf("%s is number %d and already exists\r\n",product_code1[i]);	exit(0);}
		if(strcmp(product_code2[i].name,add)==0){printf("%s is number %d and already exists\r\n",product_code2[i]);	exit(0);}
		i++;
	}
	//printf("place 1\r\n");
	printf("Please enter the product number \r\n");
	scanf("%d",&adda);
	while(i<20)
	{
		if(product_code1[i].product_number==adda){printf("%s is number %d and already exists\r\n",product_code1[i]);exit(0);}
		if(product_code2[i].product_number==adda){printf("%s is number %d and already exists\r\n",product_code2[i]);exit(0);}
		else
		 {i++;}
	}
	
	printf("How much will be in the WareHouse \r\n");
	scanf("%d",&amount);
	
	printf("So you have a product name as:%s\r\n",add);
	printf("product number as %d\r\n",adda);
	printf("and there is %d of them \r\n",amount);
	printf("Is this right Y/N\r\n");
	scanf("%s",reply);
	
	if(reply[0]=='N'||reply[0]=='n'){printf("Please enter your values again\r\n");wait_for_user();main();}
	else 
		{
			printf("Database updated,thank you\r\n");
			wait_for_user();
			main();
		}
	
}
void read_out()
{
	int k=0;
	
	while(k<20)
	{
		printf("Name:%s\t\tNumber:%d\t\tQuantity:%d\r\n",product_code1[k]);
		k++;
	}
	//printf("got here 1\r\n");
	wait_for_user();
	k=0;
		while(k<20)
	{
		printf("Name:%s\tNumber:%d\tQuantity:%d\r\n",product_code2[k]);
		k++;
	}
}
void wait_for_user()
{
	char dummy[10];
	printf("Please press a letter then enter\r\n");
	scanf("%s",dummy);
}