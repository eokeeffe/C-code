/*Evan O'Keeffe
  10324289
  Slot Machine
  started 28/01/2011
  basically how the program works is that when they choose to play the game , an initial value is placed into the credit(10)
  the player then goes through the slot functions , each function was made to make sure that each rand() function had a different
  seed (time,1,2) to make sure that there was as much probability of the functions returning a truly random number
  sadly with 3 slots means that the generator can return the same results , but only some of the time

  New features for version 2.1 is the scoreboard's function is finally complete
  the save function is nearly complete , just have to get the way it writes the new high score to be a bit neater
  also got all 3 structs working with the file at last

  although the code is long , just know that there's far more functionality with it now , menu,game and High Scores with all the little
  things working

  more comments below to show whats happening and the reasons why i did it like this

  final version of the program
  */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
//these are all the integers used in the slot part of the program in these structs
typedef struct//struct for slot 1 or column 1
{
	int slota;	//a
	int credit; //d
	int balance;//f

}slotA;
slotA a,d,f;//these act as pointers back to the structure above

typedef struct//struct for slot 2 or column 2
{
	int slotb;	//b
	int bet;	//e
}slotB;
slotB b,e;
typedef struct//struct for slot 3 or column 3
{
	int slotc;	//c
	int choice;	//g
}slotC;
slotC c,g;

//all the strings used for the program
char* fruit0;
char* fruit1;
char* fruit2;
char* result;
char* annul;
char* house_return;
char answer[10];
//the only other int
int firefly;		//the only reason this is here is because the save game function kept returning implicit declaration errors
					//and I was watching firefly the series and needed a name for a variable

//All the function prototypes, each is commented for what they do

void help();													//displays the rules of the game
void options();													//clears the screen for the menu
void game(int credit);											//the game function
void author();													//information of the author
void wait_for_user();											//wait for the user to press something before continuing
void clear_screen();											//clear the screen for ease of seeing
void create_file();												//create the save score file if it doesn't exist
void scoreboard();												//displays the best scores from the file
int check_file(FILE *fp);										//checks if save file exists
void score_save();											    //checks at the end of a game if the credits earned are high enough to be in the best scores
char* slot0();													//generator for slot 1
char* slot1();													//generator for slot 2
char* slot2();													//generator for slot 3
char* what_happened(char* fruit0,char* fruit1,char* fruit2);	//function to determine if the player has Won anything
char* house(char* fruit0,char* fruit1,char* fruit2);			//returns what house the slots have generated
void end_all();													//terminating goodbye message

int main()//small amount is actually put in here but its a good sign for me
{
	/*setvbuf(stdout , NULL , _IONBF , 0 );
	setvbuf(stderr , NULL , _IONBF , 0 );*/
	clear_screen();
	options();
	return 0;
}
void help()//explains the rules of the slot game
{
	clear_screen();
	printf("\nPress 1 to play the game \r\n");
	printf("if the fruit all match then its a full house\r\n");
	printf("if 2 are the same then its a half-house\r\n");
	printf("and if none are the same then its an empty house\r\n");
	printf("2+(your bet) coins for full house\r\n");
	printf("1+(your bet) coin for half-house\r\n");
	printf("you lose your bet for the empty house\r\n");
	wait_for_user();

}
void author()//gives some background on who created it
{
	clear_screen();
	printf("\nAuthor is Evan O'Keeffe\r\n");
	printf("Started in January 28th 2011\r\n");
	printf("Done as part of software engineering 1 2011\r\n");
	printf("Student of University College of Dublin\r\n");
	wait_for_user();
}
void wait_for_user()//wait for the user before continuing on to the next objective
{
	char dummy[10];
	printf("\nPress any letter then, enter to continue\r\n");
	scanf("%s",dummy);
	options();
}
void clear_screen()//clear the screen for the user, makes it neater and cleaner to see
{
	int i;
	for(i=0;i<25;i++)
	{printf("\n");}
}
void options()//display the options for the user
{
	clear_screen();
	printf("\nWelcome to Slot Machine version 2.1\r\n");
	printf("Here are your options\r\n\n");
	printf("1.Play Game\r\n");
	printf("2.Help\r\n");
	printf("3.Author\r\n");
	printf("4.Score board\r\n");
	printf("5.Exit\r\n");
	printf("Please enter the number for the option\r\n");
	scanf("%d",&g.choice);

		if(g.choice==1){d.credit=10;game(d.credit);}//here i initialize the credits to be 10 as the starting amount for any game

		else if(g.choice==2){help();}

		else if(g.choice==3){author();}

		else if(g.choice==4){scoreboard();}

		else
		{end_all();}
}
void game(int credit)//the main function that runs the game
{
	clear_screen();
	int a=0;
	while(a<10){answer[a]='\0';a++;}//clean the array for the asnwer
	//printf("a=%d and answer=%s\r\n",a,answer);

	time_t  timer = time(NULL);
    printf("\nTime and Date is %s\n", ctime(&timer));//casino's don't show time , so i fixed that problem


	printf("Credit available = %d \r\n",d.credit);
	printf("Please enter your bet\r\n");
	scanf("%d",&e.bet);					//Turns out if the user enters a character , then it crashes the program here
	//printf("You have bet : %d\n",bet);
	if(e.bet<=d.credit&&e.bet>=2)//check if the bet is valid
	{
					printf("Slots\r\n");
					printf("\n| %s | %s | %s |\r\n",slot0(),slot1(),slot2());//the full slot show case

					what_happened(fruit0,fruit1,fruit2);//check for a win or lose
					house(fruit0,fruit1,fruit2);//check what house the slot machine generated
					printf("\nRESULT\r\n");
					printf("%s\r\n",house_return);

					if(house(fruit0,fruit1,fruit2)=="Full_House"){e.bet=(2+e.bet);}//add 2 to the bet, if the house was full
					else if(house(fruit0,fruit1,fruit2)=="Half_House"){e.bet=(1+e.bet);}//add 1 to the bet, if the house was half full
					else
						{e.bet=-e.bet;}

					f.balance=e.bet+d.credit;//add the bet to the credit for the balance
					printf("Current Balance = %d\n\n",f.balance);
					printf("End Of Game: total amount %s = %d credits\r\n",result,e.bet);//end of game result
					printf("Do you want to Play again (y/n)?\r\n");
					scanf("%s",answer);

					if(answer[0]=='y'||answer[0]=='Y')//only check the first character in the array
					{
							if(f.balance==0||f.balance<2){printf("Sorry, but you ain't got no credit - Bye!!\r\n");end_all();}//as per requirements
							else
								{d.credit=f.balance;game(d.credit);}//place the balance into credit and return to the game function again

					}
					else
						{
							clear_screen();
							printf("End Of Game: total amount %s = %d credits\r\n",result,e.bet);
							firefly=f.balance;//had to as the function kept returning an implicit declaration error if the pointer d.credit was passed
							score_save();	//save the score if it was a high one
							end_all();
						}
	}
	else
		{game(d.credit);printf("Sorry but you don't have the credits for this bet\r\n");}

}
char* slot0()//random generator for slot 1
{
	srand(time(NULL));//each of the generators was randomly seeded to give more random numbers
	a.slota=rand()%3;
	//printf("slot0 number %d\r\n",slota);
	switch(a.slota)//i now love switch statements
	{
		case 0: {fruit0="apple";return fruit0;}
		case 1: {fruit0="pear";return fruit0;}
		default: {fruit0="orange";return fruit0;}
	}

}
char* slot1()//random generator for slot 2
{
	srand(2);
	b.slotb=rand()%3;
	//printf("slot1 number %d\r\n",slotb);
	switch(b.slotb)
	{
		case 0: {fruit1="apple";return fruit1;}
		case 1:{fruit1="pear";return fruit1;}
		default: {fruit1="orange";return fruit1;}
	}

}
char* slot2()//random generator for slot 3
{
	srand(1);
	c.slotc=rand()%3;
	//printf("slot2 number %d\r\n",slotc);
	switch(c.slotc)
	{
		case 0: {fruit2="apple";return fruit2;}
		case 1: {fruit2="pear";return fruit2;}
		default: {fruit2="orange";return fruit2;}
	}
}
void score_save()		//checks for high score then prints to the .txt file
{
	int i=0,counter=0;
	int score[100];
	char name[100],create[100],character;
	char user[20];
	FILE *fopen(),*fp;


	fp=fopen("SLOTS_BEST_SCORE.txt","r");
	if(check_file(fp)==0)
	{
		printf("Problem reading the file SLOTS_BEST_SCORE.txt, \nhave you created it yet?\r\n");
		printf("Press y to create the file , or n not to create the file \r\n");
		scanf("%s",create);
		if(create[0]=='y'||create[0]=='Y'){create_file(firefly);}//if the file doesn't exist then create it if the user wants it

		else{printf("File will not be created\r\n");end_all();}//if the user doesn't want it , then end the program
	}
	else
	{

		fp=fopen("SLOTS_BEST_SCORE.txt","r");
		i=0;
		while(fscanf(fp,"%d %s",&score[i],name)!=EOF)//scan all the lines  until the end
		{
			printf("score=%d and name=%s\r\n",score[i],name);

			i++;
			/*printf("i=%d and counter=%d\r\n",i,counter);*/
		}
		fclose(fp);
		i=0;

		fp=fopen("SLOTS_BEST_SCORE.txt","r");
		character=getc(fp);
		while(character!=EOF)
		{character=getc(fp);if(character=='\n'){i++;}}//count the number of newlines, the last one will be the highest score
		fclose(fp);//this finds the highest value score in the text file

		//printf("score=%d,i=%d\r\n",score[i],i);//debug feature to show what the score was and i
		//printf("firefly=%d\r\n",firefly);		//debug feature to show what firefly is equal to
		if(firefly>score[i])
				{
					clear_screen();
					printf("Congratulations, %d is a NEW HIGH SCORE\r\n",firefly);//tell user if its a high score
					fp=fopen("SLOTS_BEST_SCORE.txt","a");//open the document for appending
					printf("Please enter your name here\r\n");
					scanf("%s",user);
					fprintf(fp,"\r%d %s\r\n",firefly,user);//get the name and print with the score to the file
					//printf("firefly=%d and user name=%s\r\n",firefly,user);
					fclose(fp);//finally close all files
				}
				else
				{end_all();}//end the program
	}

}
void scoreboard()//displays high scores
{
	clear_screen();
	FILE *fopen(),*fp;
	int count;
	fp=fopen("SLOTS_BEST_SCORE.txt","r");

	if(check_file(fp)==0){printf("Problem reading the file SLOTS_BEST_SCORE.txt, have you created it yet?\r\n");}
	else
		{count=getc(fp);while(count!=EOF){count=getc(fp);putchar(count);}}//open the file and put the characters onto the screen
	fclose(fp);
	wait_for_user();
}
int check_file(FILE *fp)//checks if the file exists
{
	if(fp==NULL)//if file doesn't exist then return the value 0 for false
		{return 0;}
	if(fp!=NULL)//
	   {return 1;}
}
void end_all()//the good bye message and terminating function
{
	printf("Thank you for playing slot machine V 2.1\r\n");exit(0);
}
char* what_happened(char* fruit0,char* fruit1,char* fruit2)//returns if the player won or not
{
	if((fruit0)==(fruit1)){result="You Won"; return result;}
	else if(fruit0==fruit2){result="You Won"; return result;}
	else if(fruit1==fruit2){result="You Won"; return result;}
	else
		{result="You Lose";return result;}
}
char* house(char* fruit0,char* fruit1,char* fruit2)//returns the house
{
	if(((fruit0)==(fruit1))&&((fruit0)==(fruit2))){house_return="Full_House";return house_return;}
	else if((fruit0)==(fruit1)){house_return="Half_House"; return house_return;}
	else if(fruit0==fruit2){house_return="Half_House"; return house_return;}
	else if(fruit1==fruit2){house_return="Half_House"; return house_return;}
	else
		{house_return="Empty_House";return house_return;}
}
void create_file()//creates the save file
{
	FILE *fopen(),*fp;
	char* name1="Kevin_Spacey";
	char* name2="Ben_Kenobi";
	int number1=20,number2=30;

	fp=fopen("SLOTS_BEST_SCORE.txt","w");//create a file with this layout , then write sample scores into it
	fprintf(fp,"\r%d %s\r\n",number1,name1);//sample score 1
	fprintf(fp,"\r%d %s\r\n",number2,name2);//sample score 2
	fclose(fp);
	printf("File SLOTS_BEST_SCORE.txt was created\r\n");//tell the user it was made
	score_save();//go back into the function to check for high score
}
