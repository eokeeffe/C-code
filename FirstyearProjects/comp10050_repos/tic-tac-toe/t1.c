/*Evan O'Keeffe
  10324289
  Tic-Tac_Toe 
  this is the assignement 4 of software engineering projects 1st year
  
  The AI is slpit into two different types , easy and hard
  the easy one is really simplistic and will normally lose
  the hard one is the one with all the rules and also the precedence rules as well
  
  the AI also has a nice little animation which takes about 2-3seconds to make a move
  it works simply by counting and adding symbols to show its counting
  This simply makes the computer wait before going into the functions for the AI
  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//My Macro's
#define TRUE 1
#define FALSE 2
#define ERROR printf("Error at %d in file %s\r\n",__LINE__,__FILE__);
//The struct with the table in it
struct TABLE 
{
	char gt[20][20];//20x20 array for the table , this is the max width of my screen
}T;

//global variables
char comp,human;
int set,set2,set3,set4;		//set is the table dimension, set2 is who is the X or O,set3 is the AI version and set4 is who takes the first turn
int game_count;				//the overall game counter 
int ax,by;					//these are the centre of the board for all NxN greater than 3 and up to and equal 20
char dummy;					//used during debug as the carriage return capture

//Functions for the game
void setup();													//does the random generation and keeps the player input going
void diff();													//this changes if the AI will be defensive or offensive in nature
int offense();													//the offensive sequence "SMART AI"
int defense();													//defense sequences "DUMB AI"
void player1_input();											//take player 1 input
int player2();													//player 2 input (aka the computer)
void xoro();													//check whether player 1 wants to be the X or the O
int win();														//check to see one of the winning combo's and return who it was
void pvc();														//main game loop , pvc= player versus computer
int draw_table();												//function to draw the table
void GAME();													//asks for what option the user wants easy,medium,hard
void help();													//displays the rules of the game
void options();													//clears the scre for the mu
void author();													//information of the author
void wait_for_user();											//wait for the user to press something before continuing
void clear_screen();											//clear the scre for ease of seeing
void end_all();													//terminating goodbye message


int main()//start of the program, clears the screen initially then starts the options function
{
	clear_screen();
	options();
	return 0;
}

int draw_table()//draw the playing table
{
	int i,j;
	for(i=0,j=0;i<set;i++)
	{
		printf("   ");
		if(i==0){for(j=0;j<set;j++){printf(" %d \t",j);}}
		printf("\n");
		if(i<=9){printf("%d ",i);}
		if(i>9){printf("%d",i);}
		for(j=0;j<set;j++)
		{
			printf("| %c |\t",T.gt[i][j]);
		}
		printf("\r\n\n");
	}
	return 0;
}

void player1_input()//player 1 input,sadly IO problems still exist
{
	int x,y;
	fflush(stdin);
	printf("Please enter a X and Y co-ordinate for the box player 1\r\n");
	fscanf(stdin,"%d %d%*c",&x,&y);
	if( x < set && y < set && x >= 0 && y >= 0)//checks for each vector co-ord
	{
			if(T.gt[x][y]!='X'&&T.gt[x][y]!='O')
			{
				if(set2==0){T.gt[x][y]='X';}
				if(set2==1){T.gt[x][y]='O';}
			}
			else
				{printf("Values have been used, please try again\r\n");player1_input();}
	}
	else
		{printf("Please try again\r\n");player1_input();}
}

int win()//check if a player has won the match and return who won it
{
	int a,b,x,y,p1,p2,p3,p4;
	a=0;
	while(a<set)//horizontal line checking
	{
		b=0;
		p1=0;
		p2=0;
		while(b<set)
		{
			if(T.gt[a][b]==human){p1++;}
			if(T.gt[a][b]==comp){p2++;}
			if(p1==set){return 1;}
			if(p2==set){return 2;}
			b++;
		}
		a++;
	}
	//vertical line checking
	a=0;p1=0;p2=0;b=0;
	while(b<set)
	{
		if(T.gt[a][b]==human){p1++;}
		if(T.gt[a][b]==comp){p2++;}
		if(p1==set){return 1;}
		if(p2==set){return 2;}
		a++;
		if(a==set){a=0;b++;p1=0;p2=0;}//check each vertical line
	}
	//top-left to bottom-left diagonal checking
	a=0;p1=0;p2=0;b=0;x=-1;y=set;
	while(a<set)
	{
		if(T.gt[a][b]==human){p1++;}
		if(T.gt[a][b]==comp){p2++;}
		if(T.gt[x][y]==comp){p3++;}
		if(T.gt[x][y]==human){p4++;}
		if(p1==set||p4==set){return 1;}
		if(p2==set||p3==set){return 2;}
		x++;
		y--;
		a++;
		b++;
	}
	if(p1==set||p4==set){return 1;}
	if(p2==set||p3==set){return 2;}
	else
		{return 0;}
}

int defense()//defensive code , really just a easy AI , left some heruistics out so its easier
{
	int a,b,p1,p2,p3,randomx,randomy;
	a=0;
	
	//defensive strategy
	
	while(a<set)//check if human is going for a horizontal win
	{
		b=0;
		p1=0;
		p2=0;
		while(b<set)
		{
			if(T.gt[a][b]==human){p1++;}
			if(T.gt[a][b]==comp){p2++;}
			
			if(p1==set-1){p3=a;break;}//this line in particular is in trouble of losing
			if(p1==set-2){p3=a;break;}//this line in particular is in trouble of losing
			if(p2==set-1){p3=a;break;}//check if this line could win 
			if(p2==set-2){p3=a;break;}//check if this line could win 
			b++;
			
		}
		if(p1==set-1){break;}
		if(p1==set-2){break;}
		if(p2==set-1){break;}
		if(p2==set-2){break;}
		a++;
	}
	a=0;
	while(a<set)//block human horizontal win or choose to win the game
	{
		b=0;
		while(b<set)
		{
			if(p1==set-1){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&a==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
			if(p1==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&a==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
			if(p2==set-1){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&a==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
			if(p2==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&a==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
			b++;
		}
		a++;
	}
	//printf("human = %d and computer=%d\r\n",p1,p2);//vertical line checking
	a=0;p1=0;p2=0;b=0;
	while(b<set)
	{
		if(T.gt[a][b]==human){p1++;}
		if(T.gt[a][b]==comp){p2++;}
		a++;
		if(p1==set-1){p3=b; break;}
		if(p2==set-1){p3=b; break;}
		if(p1==set-2){p3=b; break;}
		if(p2==set-2){p3=b; break;}
		if(a==set){a=0;b++;p1=0;p2=0;}//check each vertical line
	}
	a=0;b=0;
	while(b<set)//block or win human vertically
	{
		if(p1==set-1){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&b==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
		if(p2==set-1){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&b==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
		if(p1==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&b==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
		if(p2==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&b==p3&&p2<0){T.gt[a][b]=comp; return 0;}}
		a++;
		if(a==set){a=0;b++;p1=0;p2=0;}//check each vertical line
	}
	//printf("human = %d and computer=%d\r\n",p1,p2);
	
	//top-right to bottom-left diagonal checking
	a=0;p1=0;p2=0;b=0;
	while(a<set)
	{
		if(T.gt[a][b]==human){p1++;}
		if(T.gt[a][b]==comp){p2++;}
		if(p1==set-1){break;}
		if(p2==set-1){break;}
		if(p1==set-2){break;}
		if(p2==set-2){break;}
		a++;
		b++;
	}
	a=0;b=0;
	while(a<set)//block human win or win on the top-right to bottom left diagonal
	{
		if(p1==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&p2<0){T.gt[a][b]=comp; return 0;}}
		if(p2==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&p2<0){T.gt[a][b]=comp; return 0;}}
		a++;
		b++;
	}
	
	//printf("human = %d and computer=%d\r\n",p1,p2);
	//top-left to bottom-right diagonal checking
	a=-1;p1=0;p2=0;b=set;
	while(a<set)
	{
		if(T.gt[a][b]==human){p1++;}
		if(T.gt[a][b]==comp){p2++;}
		if(p1==set-1){break;}
		if(p2==set-1){break;}
		if(p1==set-2){break;}
		if(p2==set-2){break;}
		a++;
		b--;
	}
	a=-1;b=set;
	while(a<set)//block or win on the top-left to bottom-right diagonal
	{
		if(p1==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&p2<0){T.gt[a][b]=comp; return 0;}}
		if(p2==set-2){if(T.gt[a][b]!=human&&T.gt[a][b]!=comp&&p2<0){T.gt[a][b]=comp; return 0;}}
		a++;
		b--;
	}
	//printf("human = %d and computer=%d\r\n",p1,p2);
	
	//offensive strategy or non defensive
	
	randomx=rand()%set;
	a=0;
	printf("Analyzing Board\r\n");
	while(a<1000000){a++;}//allow a second to go by
	randomy=rand()%set;
	if(T.gt[randomx][randomy]!=human&&T.gt[randomx][randomy]!=comp)
	{ T.gt[randomx][randomy]=comp; return 0;}//starting the match this will happen 
	
}

int offense()//offense code , the more aggresive AI that follows all of the rules in the requirements
{
	int x,y;
	int a,b;
	int rx,ry;
	int diag1=0,diag2=0,diag3=0,diag4=0,h1=0,h2=0,v1=0,v2=0;
	
	if(T.gt[ax][by]!=comp&&T.gt[ax][by]!=human)//take the centre if possible
	{
		if(set%2==0){ax=set/2;by=set/2;}
		if(set%2!=0){ax=((set/2)+1);by=((set/2)+1);}//if 5x5 of other odd number then choose the rough centre
		
		if(T.gt[ax][by]!=human&&T.gt[ax][by]!=comp){T.gt[ax][by]=comp; return 0;}
	}
	
	//This is the analysis of the full board, takes every line and counts each occurence and then 
	//sends the analysis to the conditions below
	
	//diagonals
	a=-1;b=set;x=set;y=-1;
	while(a<set&&y<set)
	{
		if(T.gt[a][b]==comp){diag1++;}
		if(T.gt[a][b]==human){diag2++;}
		if(T.gt[x][y]==comp){diag3++;}
		if(T.gt[x][y]==human){diag4++;}
		if(diag1==set-1){break;}
		if(diag2==set-1){break;}
		if(diag3==set-1){break;}
		if(diag4==set-1){break;}
		a++;
		b--;
		x--;
		y++;
	}
	//horizontal
	a=0;b=0;
	while(a<set)
	{
		b=0;
		while(b<set)
		{
			if(T.gt[a][b]==comp){h1++;}
			if(T.gt[a][b]==human){h2++;}
			if(h1==set-1){break;}
			if(h2==set-1){break;}
			b++;
		}
		a++;
	}
	//vertical
	x=0;y=0;
	while(y<set)
	{
		if(T.gt[x][y]==comp){v1++;}
		if(T.gt[x][y]==human){v2++;}
		if(v1==set-1){break;}
		if(v2==set-1){break;}
		x++;
		if(x==set){x=0;y++;v1=0;v2=0;}
	}
	
	
	//printf("d1=%d,d2=%d,d3=%d,d4=%d,h1=%d,h2=%d,v1=%d,v2=%d\r\n",diag1,diag2,diag3,diag4,h1,h2,v1,v2);//debug routine
	//These are the conditions of the AI , this was from the requirements sheet
	
	//CONDITION 1
	if(diag1==set-1)//if the computer can win then win on the first diagonal
	{
		a=-1;b=set;
		while(a<set)
		{
			if(T.gt[a][b]!=comp&&T.gt[a][b]!=human){T.gt[a][b]=comp; return 0;}
			a++;
			b--;
		}
	}
	if(diag3==set-1)//other diagonal win
	{
		y=-1;x=set;
		while(y<set)
		{
			if(T.gt[x][y]!=comp&&T.gt[x][y]!=human){T.gt[x][y]=comp;return 0;}
			y++;
			x--;
		}
	}
	if(h1==set-1)//horizontal win,look for the line and then fill something at that line
	{
		int temp;
		a=0;b=0;h1=0;
		while(a<set)
		{
			b=0;
			while(b<set)
			{
				if(T.gt[a][b]==comp){h1++;}
				if(h1==set-1){temp = a; break;}
				b++;
			}
			a++;
		}
		
		a=0;b=0;h1=0;
		while(a<set)
		{
			b=0;
			while(b<set)
			{
				if(a==temp){if(T.gt[a][b]!=comp&&T.gt[a][b]!=human){T.gt[a][b]=comp; return 0;}}
				b++;
			}
			a++;
		}
		
		
	}
	if(v1==set-1)//vertical win,look for the vertical line and then fill a space on it
	{
		int temp=0;
		x=0;y=0;v1=0;
		while(y<set)
		{
			if(T.gt[x][y]==comp){v1++;}
			if(v1==set-1){temp=b;break;}//find the line
			x++;
			if(x==set){x=0;y++;}
		}
		
		x=0;y=0;
		while(y<set)
		{
			if(T.gt[x][y]!=comp&&T.gt[x][y]!=human&&temp==b){T.gt[x][y]=comp; return 0;}
			x++;
			if(x==set){x=0;y++;}
		}
	}
	//CONDITION 2
	if(diag2==set-1)//if the user can win on the first diagonal then block
	{
		a=-1;b=set;
		while(a<set)
		{
			if(T.gt[a][b]!=comp&&T.gt[a][b]!=human){T.gt[a][b]=comp; return 0;}
			a++;
			b--;
		}
	}
	if(diag4==set-1)//if the user can win on the first diagonal then block
	{
		y=-1;x=set;
		while(x<set)
		{
			if(T.gt[x][y]!=comp&&T.gt[x][y]!=human){T.gt[x][y]=comp;return 0;}
			y++;
			x--;
		}
	}
	if(h2==set-1)//block HUMAN on the horizontal
	{
		int temp;
		a=0;b=0;h2=0;
		while(a<set)
		{
			b=0;
			while(b<set)
			{
				if(T.gt[a][b]==human){h2++;}
				if(h2==set-1){temp = a; break;}
				b++;
			}
			a++;
		}
		
		a=0;b=0;h1=0;
		while(a<set)
		{
			b=0;
			while(b<set)
			{
				if(a==temp){if(T.gt[a][b]!=comp&&T.gt[a][b]!=human){T.gt[a][b]=comp; return 0;}}
				b++;
			}
			a++;
		}
	}
	if(v2==set-1)//block on the vertical
	{
		int temp=0;
		x=0;y=0;v1=0;
		while(y<set)
		{
			if(T.gt[x][y]==comp){v1++;}
			if(v1==set-1){temp=b;break;}//find the line
			x++;
			if(x==set){x=0;y++;}
		}
		
		x=0;y=0;
		while(y<set)
		{
			if(T.gt[x][y]!=comp&&T.gt[x][y]!=human&&temp==b){T.gt[x][y]=comp; return 0;}
			x++;
			if(x==set){x=0;y++;}
		}
	}
	else if(T.gt[ax][by]==comp)//condition 3 is if the comp controls the centre then take any adjacent
	{
		int random=0;
		random=rand();
		x=rand()%set;
		
		if(random%3==0)//go vertical
		{
			x=0;y=0;
			while(y<set)
			{
				y=rand()%set;
				if(T.gt[x][y]!=comp&&T.gt[x][y]!=human){T.gt[x][y]=comp; return 0;}
				x++;
				if(x==set){x=0;y++;}
			}
		}
		if(random%4==0)//go horizontal
		{
			a=0;b=0;
			while(a<set)
			{
				b=0;
				while(b<set)
				{
					y=rand()%set;
					if(T.gt[x][y]!=comp&&T.gt[x][y]!=human){T.gt[x][y]=comp; return 0;}
					b++;
				}
				a++;
			}
		}
	}
	else//condition 7, if no other rules come about then take any open space
	{
		
		rx = rand() % set;
		a=0;
		while(a<10000000){a++;}//allow a second to go by to get another random number
		ry=rand()%set;
		if(T.gt[rx][ry]!=human&&T.gt[rx][ry]!=comp)
		{ T.gt[rx][ry]=comp; return 0;}//stop from the computer taking more moves 
		else
			{offense();}
	}
}

int player2()//player 2 computer input.This holds the A.I defense and offense routines
{	
	int wait,x,y;
	wait=0;
	while(wait<150000000)
	{
		if(wait==0){printf("Analyzing Board -");}//i liked this little animation so i left it in
		if(wait%10000000==0){printf("-");}
		wait++;
	}
	printf("Heuristic matched\r\n");
	if(game_count==0)
	{
		if(set%2==0){x=(set/2);y=(set/2);}
		if(set%2!=0){x=((set/2)+1);y=((set/2)+1);}
		if(T.gt[x][y]!='X'&&T.gt[x][y]!='O'){T.gt[x][y]=comp; return 0;}
	}
	if(set3==0){defense();}
	if(set3==1){offense();}
	return 0;
}

void xoro()//sets the player 1 to be either X or O, which will set the computer to either X or O
{
	char who[50];
	printf("Human do you want to be X or O\r\n");
	printf("Please enter one of the following\r\n");
	printf("X to be X Or O to be O\r\n");
	scanf("%s",&who);
	if(who[0]=='x'||who[0]=='X'){set2=0; pvc();}
	if(who[0]=='o'||who[0]=='O'){set2=1; pvc();}
	else
		{printf("Sorry invalid character please try again\r\n"); xoro();}
}

void setup()//decides if the human or computer goes first by picking randomly
{
	int who_goes_first;
	who_goes_first=0;
	who_goes_first=rand();
	//printf("who goes first=%d\r\n",who_goes_first);
	if(who_goes_first%3==0){set4=0;}//human first
	if(who_goes_first%4==0){set4=1;}//computer first
}

void pvc()//main game loop, tried to keep this smaller than usual
{
	if(set2==0){comp='O';human='X';}//set the player identity
	if(set2==1){comp='X';human='O';}
	
	game_count=0;//initialize the main game counter to zero
	//initial starting 
	setup();//get the random first player
	if(set4==0){printf("Human first\r\n");}//show who is first
	if(set4==1){printf("Computer first\r\n");}
	
	while(win()==0||game_count<=(set*set))
	{
		//if(game_count==0){draw_table();}//draw starting board
		if(set4==0)//if player 1 is to be first everytime
		{
			draw_table(); 
			player1_input(); 
			game_count++;
			if(game_count==(set*set)){break;}
			fflush(stdin);  
			if(win()!=0){draw_table();break;}  
			draw_table(); 
			player2(); 
			if(win()!=0){draw_table();break;} 
			game_count++;
			if(game_count==(set*set)){break;}			
			draw_table;
			printf("game_count=%d\r\n",game_count);
		}
		if(set4==1)//if computer is to be first everytime
		{
			draw_table(); 
			player2(); 
			game_count++;	
			if(game_count==(set*set)){break;}
			if(win()!=0){draw_table();break;} 
			draw_table(); 
			player1_input();
			game_count++;
			if(game_count==(set*set)){break;}
			if(win()!=0){draw_table();break;} 
			fflush(stdin); 
			draw_table();
			printf("game_count=%d\r\n",game_count);
		}
	}
	draw_table();
	if(win()==1||win()==4){printf("\nThe Human player has won the match\r\n");}//show who has won the match
	else if(win()==2||win()==3){printf("\nThe Computer player has won the match\r\n");}
	else
		{printf("\nMATCH HAS ENDED IN A DRAW\r\n");}
	fflush(stdin);
	wait_for_user();
	GAME();
}

void set_table()//set how big the table is going to be
{
	int choice;
	set=0;
	printf("Please enter a number for the table set\r\n");
	printf("The number must be between 3 and 20\r\n");

	fscanf(stdin,"%d",&choice);
	if(choice>=3&&choice<=20){set=choice; GAME();}
	else
		{printf("Please enter a valid number\r\n"); set_table();}
}

void GAME()//ask the user if they want to play,change table size,change AI or go back to the main menu or quit
{
	fflush(stdin);
	srand(time(NULL));
	clear_screen();
	int i,k,user_choice;
	for(i=0;i<set;i++){for(k=0;k<set;k++){T.gt[i][k]='\0';}}//clean the game table for each match
	user_choice=0;
	printf("Please enter a number for the corresponding function\r\n\n");
	printf("1.Player versus computer\r\n\n");
	printf("2.Change table dimensions\tCurrent Dimension=%d\r\n\n",set);
	printf("3.Return to main options screen\r\n\n");
	if(set3==0){printf("4.change A.I system\t\tCurrent A.I is set to easy\r\n\n");}
	if(set3==1){printf("4.change A.I system\t\tCurrent A.I is set to hard\r\n\n");}
	printf("5.Quit\r\n\n");
	printf("Please enter your choice\r\n");
	scanf("%d%*c",&user_choice);
	if(user_choice==1){xoro();}
	if(user_choice==2){set_table();}
	if(user_choice==3){options();}
	if(user_choice==4){diff();}
	if(user_choice==5){end_all();}
	else
	{
		printf("Please enter a valid choice\r\n");
		wait_for_user();
		GAME();
	}

}

void diff()//change the A.I type
{
	char word[50];
	printf("Do you want the AI to be easy or hard?\r\n");
	printf("E for easy and H for hard\r\n");
	scanf("%s",&word);
	if(word[0]=='e'||word[0]=='E'){	set3=0;	}
	else if(word[0]=='h'||word[0]=='h'){	set3=1;	}
	else if(word[0]!='h'&&word[0]!='h'&&word[0]!='e'&&word[0]!='E')
	{printf("Please enter a correct letter\r\n");diff();}
}

void wait_for_user()//wait for the user to press something
{
	char dummy1[400];
	int i;
	for(i=0;i<400;i++){dummy1[i]='\0';}
	printf("\nPress enter to continue\r\n");
	dummy=getchar();
}

void clear_screen()//clear the screen
{
	int i;
	for(i=0;i<30;i++)
	{printf("\n");}
}

void end_all()//end game function
{
	clear_screen();
	printf("Game is Over..GoodBye\r\n");
	printf("Thank you for playing Tic-Tac-Toe V1.2\r\n");
	exit(0);
}

void author()//info about the author
{
	clear_screen();
	printf("\nAuthor is Evan O'Keeffe\r\n");
	printf("Started on April 4th 2011\r\n");
	printf("Project 4\r\n");
	printf("Done as part of software engineering 1 2011\r\n");
	printf("Student of University College of Dublin\r\n");
	wait_for_user();
	options();
}

void help()//simple help screen so people know how the game works
{
	clear_screen();
	printf("The player plays against the AI to win\r\n");
	printf("You have to get a line of whatever characater you are, eg X,0\r\n");
	printf("The line can be diagonal or vertical or horizontal\r\n");
	printf("Win by getting a full run diagonally or horizontally or vertically\r\n");
	printf("The table size can be changed to whatever the user wants from minimum 3 to maximum 20\r\n");
	printf("The AI has difficulty settings which will give the user varying playing challenges\r\n");
	printf("The two difficulties are Easy and Hard\r\n");
	wait_for_user();
	options();
}

void options()//show the options
{
	int user_choice;
	set=3;
	clear_screen();
	printf("Tic-Tac-Toe version 1.2\r\n");
	printf("Please input a number for the option\r\n");
	printf("1.Play Tic-Tac-Toe\r\n");
	printf("2.Help\r\n");
	printf("3.Author\r\n");
	printf("4.Exit\r\n");
	user_choice=0;
	scanf("%d%*c",&user_choice);
	if(user_choice==1){GAME();}
	if(user_choice==2){help();}
	if(user_choice==3){author();}
	if(user_choice==4){end_all();}
	else
	{
		printf("Please try again with a number specified\r\n");
		wait_for_user();
		options();
	}

}