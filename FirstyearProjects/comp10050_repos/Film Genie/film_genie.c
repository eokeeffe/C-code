/*Evan O'Keeffe
  10324289
  Film Genie game for first year software engineering 2011

  So the structure of the code is as follows
  1.take user input for the menu
  2.if 1 is pressed then check the file , if exists then get a name, else create the file
  3.if the file has been tampered with , re-create the file
  4.get a random number
  5.while the loop count != random number, stop at the random number and read into a string
  6.clean the film string of any weird characters then change it to uppercase
  7.ask the user for c or f
  8.if c , accept a string but only take 2 characters where only 1 is used and changed to toupper
  9.check each part of the film string for that letter then proceed with either true or false return
  10.if f is input , take a string that is only as long as the film name itself plus the spaces
  11.if f is correct then proceed to say what kinda score they achieved , i.e your a genuis-phew that was a close one
  12.ask if they want to play again , if y then read_file again
  13.if n then quit the program
  14.if anything else then reapeat the question 10 more times before returning to the main menu
  15.repeat loop if neccesary
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// all the defines
#define buffsize 32
//5 tries per guess
#define number_of_tries 5
#define TRUE 1
#define FALSE 2


#define ERROR printf("Your file film_genie has been corrupted,program will now generate the backup file\r\n");

int random1;		//random number that will be the line that the fgets scans and reads in to the string called film
char dummy;
char user_answer;
char play_again[400];

//functions of the program
void help();													//displays the rules of the game
void options();													//clears the screen for the menu
void author();													//information of the author
void wait_for_user();											//wait for the user to press something before continuing
void clear_screen();											//clear the screen for ease of seeing
void read_file();												//read the file and check if exists and ask to create if not
void create_file();												//create a simple movie list file
void get_name();												//get a random name from the file and pass to the film_genie function
void end_all();													//terminating goodbye message
void film_genie(char* film);									//film genie game function
void read_out();												//a simple function to check if the file is being read
int check_file(FILE *fp);										//checks if save file exists
char get_choice();												// asks the user for the character or string input
int file_fecked(FILE *fp);										//check if the file has been purposely corrupted

void main()//haha 2 lines long
{
	//setvbuf(stdout , NULL , _IONBF , 0 );				// left these in to check that it worked in ecplise
	//setvbuf(stderr , NULL , _IONBF , 0 );
	clear_screen();
	options();
}

void options()//show the options
{
	int user_choice;
	clear_screen();
	fflush(stdin);
	printf("Welcome to Film Genie version 1.0\r\n");
	printf("Please input a number for the option\r\n");
	printf("1.Play Film Genie\r\n");
	printf("2.Help\r\n");
	printf("3.Author\r\n");
	printf("4.Exit\r\n");
	scanf("%d",&user_choice);
	dummy=getchar();
	if(user_choice==1){read_file();}
	if(user_choice==2){help();}
	if(user_choice==3){author();}
	if(user_choice==4){end_all();}
	if(user_choice==5){read_out();}//mainly for diagnostics on the file
	else
	{printf("Please try again with a number specified\r\n");wait_for_user();options();}

}

void read_out()//reads out the file,included just for the testing purposes and diagnostics on the file
{
	FILE *fopen(),*fp;
	char choice[100];
	int c;

	fp=fopen("film_genie.txt","r");
	c=getc(fp);
	while(c!=EOF)
	{c=getc(fp);putchar(c);}//read out the text file
	fclose(fp);
	wait_for_user();
	options();
}

void read_file()//do all the checks on the file that contains the film names
{
	FILE *fopen(),*fp;
	char choice[100];

	fp=fopen("film_genie.txt","r");

	if(check_file(fp)==0)//if it doesn't exist then create a simple file
	{
		printf("There is a backup file that can be made, \nit has only 40 something film names though?\r\n");
		printf("Please press Y to create the file or N to not make it and exit\r\n");
		scanf("%s",choice);
		if(choice[0]=='Y'||choice[0]=='y'){fclose(fp);create_file();}
		if(choice[0]=='N'||choice[0]=='n'){fclose(fp);end_all();}
	}
	if(check_file(fp)==1)//if it does exist then just get a film name
	{
		if(file_fecked(fp)==TRUE){fclose(fp);get_name();}
		else
			{
				fclose(fp);
				ERROR
				create_file();// if someone decides to corrupt the file genie txt file then the program will generate the backup file
			}
	}
}

int file_fecked(FILE *fp)//check the file and if the file has less than 5 letters then the file has been tampered
{
	int c=0,count=0;

	c=getc(fp);
	while(c!=EOF)
	{
		c=getc(fp);
		if((c>=65&&c<=90)||(c>=97&&c<=122)){count++;}
	}
	if(count<5){return FALSE;}//5 is string lenght of ALIENS , the shortest film name
	if(count>=5){return TRUE;}
}

void get_name()//using random() , scan a specific line for a film name
{
	fflush(stdin);
	FILE *fopen(),*fp;
	char* film_name[buffsize];//not used , only occurs one in the code , but if i remocve this the code breaks?????
	char film[400];
	int i,count=0;
	fp=fopen("film_genie.txt","r");
	fflush(fp);
	for(i=0;i<400;i++){film[i]='\0';}
	random();										//generate a random number that will be used to pick a random movie name

	//printf("random number = %d \r\n",random1);
	while(count!=random1)
	{
		fgets(film,buffsize,fp);					//using the random number , this will scan the name of the movie
		//printf("%s\n",film);
		count++;
	}
	fclose(fp);
	film_genie(film);
}

void film_genie(char* film)//the function for the film-genie game
{
	fflush(stdin);

	int i=0,count=0,string_length=0,comparison=0,comparison2=0,comparison3=0,x=0,spaces=0;

	char guess[400],guess_upper_string[400],guess_upper;

	char string[(strlen(film))];				//create an array big enough to hold all characters including spaces and null

	for(i=0;i<(strlen(film));i++){string[i]='\0';}	//clean the array so that when it comes to comparisons they will match
	for(i=0;i<400;i++){guess[i]='\0';}				//clean the guess array

	for(i=0;i<strlen(film);i++){string[i]='*';}	//fill the string array with * to show the number of characters that have to be guessed by the user
	string[strlen(film)]='\0';
	//printf("string is size %d after *'s\r\n",strlen(string));		//debug for showing how many stars are in the array

	for(i=0;i<strlen(film);i++){film[i]=toupper(film[i]);}	//convert everything to upper-case
	for(i=0;i<=strlen(film);i++){if(film[i]>64&&film[i]<123||film[i]==32){string_length++;}}
	//get the total number of characters and spaces and nothing else
	for(i=0;i<=strlen(film);i++){if(film[i]==32){spaces++;}}		//count the number of spaces , used in the character number checker
	for(i=0;i<=strlen(film);i++){if(film[i]<65&&film[i]>122&&film[i]!=32){film[i]='\0';}}		//null any characters present in film
	i=0;

	while(count<number_of_tries&&comparison!=(string_length-spaces)&&comparison2!=string_length)
	//if the number of tries goes to far , or they get the full thing
	{
		fflush(stdin);
		clear_screen();
		//printf("higher case film = %s\r\n",film);

		printf("Guess number:%d\r\n",count);
		printf("previous guess was:%s\r\n",guess);
		printf("number of characters=%d\r\n",string_length);
		printf("here is the string so far %s\r\n",string);
		get_choice();

		if(user_answer=='c'||user_answer=='C')
		{
			fflush(stdin);
			printf("\nplease enter a character\r\n");
			scanf("%2s",&guess);
			fflush(stdin);
			//printf("you entered %s\r\n",guess);
			for(i=0;i<=strlen(film);i++)//check for all characters that may match the guess
			{
					guess_upper=toupper(guess[0]);
					if(guess_upper==film[i]){string[i]=guess_upper;comparison++;}//if the guess is right replace the star in string with the character
					//and increment the comparison count(count until all letters have been guessed
			}
			//printf("comp=%d and sl=%d ,counter=%d\r\n",comparison,string_length,i);

			if(comparison==comparison3){count++;printf("Your character doesn't exist! Please continue playing\r\n");}
			//if the guess was incorrect then the comparison will be equal to comparison3
			else{comparison3=comparison;}//else the guess was right
			wait_for_user();
			fflush(stdin);
		}

		if(user_answer=='f'||user_answer=='F')
		{
			fflush(stdin);
			for(i=0;i<400;i++){guess[i]='\0';}
			for(i=0;i<400;i++){guess_upper_string[i]='\0';}
			i=0;

			printf("\nplease enter the full film name\r\n");


			for(x=0;guess[x]!='\r'&&x<=string_length&&guess[x]!='\n';x++){guess[x]=getchar();}
			//because scanf was giving me errors , i wrote my own version of it here
			fflush(stdin);
			//printf("you entered %s\r\n",guess);
			comparison2=0;

			for(i=0;i<=strlen(film);i++)//check for all characters that may match the guess
			{
					guess_upper_string[i]=toupper(guess[i]);
					//printf("guess=%c and film=%c\r\n",guess_upper_string[i],film[i]);
					if(guess_upper_string[i]==film[i]){string[i]=guess_upper_string[i];comparison2++;}
					//if the guess is right replace the star in string with the character
					if(comparison2==string_length){break;}
					//if all characters are matched then the guess is right , also handy if they only mispelled a single part of a long string
			}
			//printf("comp=%d and sl=%d ,counter=%d,string=%s\r\n",comparison2,string_length,comparison3,string);
			if(comparison2!=string_length){count++;}
			if(comparison2==comparison3){printf("Your character doesn't exist! Please continue playing\r\n");}
			//if the guess was incorrect then the comparison will be equal to comparison3
			else
				{comparison3=comparison;}		  //else the guess was right
			wait_for_user();
			fflush(stdin);
		}
		else
			{printf("please try again\r\n");wait_for_user();}

	}

	clear_screen();

	if(count>number_of_tries){printf("sorry but that wasn't the right answer\r\n");printf("%s was the right answer\r\n",film);}
	if(count==5){printf("That was a lucky one , well done\r\n");}
	if(count==0){printf("Your a Genius , well done\r\n");}
	else{printf("Congratulations You Won, %s was the right answer\r\n",film);}

	fflush(stdin);
	for(i=0;i<400;i++){play_again[i]='\0';}
	i=0;
	printf("would you like to continue playing?\r\n");
	printf("Y to continue or N to quit\r\n");
	scanf("%s",&play_again);
	fflush(stdin);
	if(play_again[0]=='y'||play_again[0]=='Y'){read_file();}
	if(play_again[0]=='n'||play_again[0]=='N'){end_all();}
	else
	{
		fflush(stdin);
		for(i=0;i<400;i++){play_again[i]='\0';}
		i=0;
		printf("wrong input, please try again\r\n");
		wait_for_user();
		printf("would you like to continue playing?\r\n");
		printf("Y to continue or N to quit\r\n");
		scanf("%s",&play_again);
		fflush(stdin);
		if(play_again[0]=='y'||play_again[0]=='Y'){read_file();}
		if(play_again[0]=='n'||play_again[0]=='N'){end_all();}
		else
		{
			for(i=0;i<400;i++){play_again[i]='\0';}
			i=0;
			while(i<10)//10 times is trying it really
			{
				printf("\nwould you like to continue playing?\r\n");
				printf("Y to continue or N to quit\r\n");
				scanf("%s",&play_again);
				if(play_again[0]=='y'||play_again[0]=='Y'){read_file();}
				if(play_again[0]=='n'||play_again[0]=='N'){end_all();}
				else{printf("character not recognized, please try again\r\n");i++;}
			}
			if(i==10){clear_screen();printf("Now redirecting you to the main menu , please don't try that again\r\n");wait_for_user();options();}
		}
	}
}

char get_choice()
{
	user_answer='\0';
	printf("Press C to guess a character\r\n");
	printf("Press F to guess the whole film name\r\n");
	scanf("%c",&user_answer);
	fflush(stdin);
	//printf("char=%c\r\n",user_answer);
	return user_answer;
}

int random()//generate random number to get a random movie from the list in the file
{
	srand(time(NULL));
	random1=(rand()%44);
	if(random1<1){random();}
	else
	{return random1;}
}

void author()//info about the author
{
	clear_screen();
	printf("\nAuthor is Evan O'Keeffe\r\n");
	printf("Started in Febuary 18th 2011\r\n");
	printf("Project 2\r\n");
	printf("Done as part of software engineering 1 2011\r\n");
	printf("Student of University College of Dublin\r\n");
	wait_for_user();
	options();
}

void help()//simple help screen so people know how the game works
{
	clear_screen();
	printf("So the whole point of the game is to guess\r\n");
	printf("the name of the movie , don't worry higher and lower \r\n");
	printf("case are both taken into account so that won't matter here\r\n");
	printf("You can guess either the indivual characters or guess the name straight off\r\n");
	wait_for_user();
	options();
}

void wait_for_user()//wait for the user to press something
{
	char dummy1[400];
	int i;
	for(i=0;i<400;i++){dummy1[i]='\0';}
	printf("\nPress any letter then, enter to continue\r\n");
	scanf("%s",dummy1);
	dummy=getchar();
}

void clear_screen()//clear the screen
{
	int i;
	for(i=0;i<25;i++)
	{printf("\n");}
}

void end_all()//end game function
{
	clear_screen();
	printf("Game is Over..GoodBye\r\n");
	printf("Thank you for playing Film Genie V1.0\r\n");
	exit(0);
}

int check_file(FILE *fp)//checks if the file exists
{
	if(fp==NULL)//if file doesn't exist then return the value 0 for false
		{return 0;}
	if(fp!=NULL)//
	   {return 1;}
}

void create_file()//becuase i don't like it when someone doesn't take into account what would happen if the film file wasn't included
{//this creates the file if it doesn't exist
	char* name0="The Godfather";
	char* name1="Citizen Kane";
	char* name2="Casablanca";
	char* name3="Chinatown";
	char* name4="Raging Bull";
	char* name5="La Dolce Vita";
	char* name6="Gone With The Wind";
	char* name7="Some Like It Hot";
	char* name8="Singing In The Rain";
	char* name9="Psycho";
	char* name10="Seven Samurai";
	char* name11="The Searchers";
	char* name12="The Gold Rush";
	char* name13="Star Wars";
	char* name14="On The Waterfront";
	char* name15="Lawrence of Arabia";
	char* name16="Vertigo";
	char* name17="All About Eve";
	char* name18="The Bicycle Thief";
	char* name19="Snow White And The Seven Dwarfs";
	char* name20="Bringing Up Baby";
	char* name21="Intolerance";
	char* name22="A Space Odyssey";
	char* name23="The Grapes of Wrath";
	char* name24="Sunset Boulevard";
	char* name25="Pulp Fiction";
	char* name26="Mr. Smith Goes to Washington";
	char* name27="The Maltese Falcon";
	char* name28="The Wizard of Oz";
	char* name29="Jules and Jim";
	char* name30="The Philadelphia Story";
	char* name31="Blue Velvet";
	char* name32="Nashville";
	char* name33="Swing Time";
	char* name34="Schindlers List";
	char* name35="Taxi Driver";
	char* name36="Aliens";
	char* name37="Duck Soup";
	char* name38="North By Northwest";
	char* name39="The Seventh Seal";
	char* name40="The Bridge On The River Kwai";
	char* name41="King Kong";
	char* name42="Bonnie And Clyde";
	char* name43="Sweet Smell of Success";
	char* name44="Double Indemnity";

	FILE *fopen(),*fp;
	fp=fopen("film_genie.txt","w");//create a file with this layout
	fprintf(fp,"%s\n",name0);
	fprintf(fp,"%s\n",name1);
	fprintf(fp,"%s\n",name2);
	fprintf(fp,"%s\n",name3);
	fprintf(fp,"%s\n",name4);
	fprintf(fp,"%s\n",name5);
	fprintf(fp,"%s\n",name6);
	fprintf(fp,"%s\n",name7);
	fprintf(fp,"%s\n",name8);
	fprintf(fp,"%s\n",name9);
	fprintf(fp,"%s\n",name10);
	fprintf(fp,"%s\n",name11);
	fprintf(fp,"%s\n",name12);
	fprintf(fp,"%s\n",name13);
	fprintf(fp,"%s\n",name14);
	fprintf(fp,"%s\n",name15);
	fprintf(fp,"%s\n",name16);
	fprintf(fp,"%s\n",name17);
	fprintf(fp,"%s\n",name18);
	fprintf(fp,"%s\n",name19);
	fprintf(fp,"%s\n",name20);
	fprintf(fp,"%s\n",name21);
	fprintf(fp,"%s\n",name22);
	fprintf(fp,"%s\n",name23);
	fprintf(fp,"%s\n",name24);
	fprintf(fp,"%s\n",name25);
	fprintf(fp,"%s\n",name26);
	fprintf(fp,"%s\n",name27);
	fprintf(fp,"%s\n",name28);
	fprintf(fp,"%s\n",name29);
	fprintf(fp,"%s\n",name30);
	fprintf(fp,"%s\n",name31);
	fprintf(fp,"%s\n",name32);
	fprintf(fp,"%s\n",name33);
	fprintf(fp,"%s\n",name34);
	fprintf(fp,"%s\n",name35);
	fprintf(fp,"%s\n",name36);
	fprintf(fp,"%s\n",name37);
	fprintf(fp,"%s\n",name38);
	fprintf(fp,"%s\n",name39);
	fprintf(fp,"%s\n",name40);
	fprintf(fp,"%s\n",name41);
	fprintf(fp,"%s\n",name42);
	fprintf(fp,"%s\n",name43);
	fprintf(fp,"%s\n",name44);
	fclose(fp);
	printf("Film_genie.txt was created\r\n");//tell the user it was made
	wait_for_user();
	options();
}
