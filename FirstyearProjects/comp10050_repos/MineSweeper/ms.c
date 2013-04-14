/*Evan O'Keeffe
  10324289
  MineSweeper program
  How this program works is there are two 2-dimensional arrays 
  the first one holds a built up map of the minefield 
  the second is the where the users choice shows up and then the surroundings are revealed as long as they're not mines
  the arrays have numbered markings on both sides to help with choosing vectors in the game
  
  the loop is stopped when either the number of spaces in the guessing array are less than total-number of mines
  or if the user hits a mine , then all mines are shown
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#define ERROR printf("Error at %d in file %s\r\n",__LINE__,__FILE__);

int user_choice,user_choice1;
int i,j,a,b,c,d,e;
int x,y;
int randomn,randomh;
char answer[100];
char dummy;
clock_t start, end;//define the clock funtion timer , this will give a time for how long the game has been played


typedef struct		//easy difficulty
{
	char easys[9][9];
	char easyc[9][9];
}Easy;

typedef struct		//medium difficulty
{
	char mediums[16][16];
	char mediumc[16][16];
}Medium;

typedef struct 		//hard difficulty
{			  //y,x
	char hards[30][16];
	char hardc[30][16];
}Hard;

//struct variables
Easy E;
Medium M;
Hard H;

void EASY();													//easy game option
void MEDIUM();													//medium game option
void HARD();													//hard game function
void GAME();													//asks for what option the user wants easy,medium,hard
void help();													//displays the rules of the game
void options();													//clears the scre for the mu
void author();													//information of the author
void wait_for_user();											//wait for the user to press something before continuing
void clear_screen();											//clear the scre for ease of seeing
void end_all();													//terminating goodbye message


int main()//start of the program, clears the scre initially th starts the options function
{
	clear_screen();
	options();
	return 0;
}

void EASY()//easy game function, steps are clean , populate and final game loop
{
	for(i=0;i<10;i++)//clean array
	{
		for(j=0;j<10;j++)
		{E.easys[i][j]='*';E.easyc[i][j]=' ';}
	}
	c=0;
	for(i=0,j=0;c<10;i++)//populate the minefield with 10  mines
	{
		a=0;
		for(j=0;j<10;j++)
		{
			if(j==(rand()%9)&&a<3&&E.easys[i][j]!='M')//a is the line counter so here im saying I want no more than 3 mines per line
			{
				E.easys[i][j]='M';
				//printf("c=%d\r\n",c);
				c++;
				a++;
			}
			if(E.easys[i][j]!='M'){E.easys[i][j]='*';}
		}
		if(i==9){i=0;}
	}
	a=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(E.easys[i][j]=='M'){a++;}
			else 
				continue;
		}
	}
	printf("%d mines are in the array\r\n",a);
	for(i=0,j=0;i<40;i++)//populate the proximity bounds
	{
		for(j=0;j<40;j++)
		{
			if(E.easys[i][j]=='M')
			{
				if(E.easys[i-1][j-1]!='M'){E.easys[i-1][j-1]='1';}
				if(E.easys[i-1][j]!='M'){E.easys[i-1][j]='1';}
				if(E.easys[i-1][j+1]!='M'){E.easys[i-1][j+1]='1';}
				if(E.easys[i][j-1]!='M'){E.easys[i][j-1]='1';}
				if(E.easys[i][j+1]!='M'){E.easys[i][j+1]='1';}
				if(E.easys[i+1][j-1]!='M'){E.easys[i+1][j-1]='1';}
				if(E.easys[i+1][j]!='M'){E.easys[i+1][j]='1';}
				if(E.easys[i+1][j+1]!='M'){E.easys[i+1][j+1]='1';}
			}
		}
	}
	for(i=0,j=0;i<40;i++)//populate the proximity bounds
	{
		for(j=0;j<40;j++)
		{
			if(E.easys[i][j]=='M')
			{
				if(E.easys[i-2][j-2]!='M'&&E.easys[i-2][j-2]!='1'){E.easys[i-2][j-2]='2';}
				if(E.easys[i-2][j-3]!='M'&&E.easys[i-2][j-3]!='1'){E.easys[i-2][j-3]='2';}
				if(E.easys[i-2][j+3]!='M'&&E.easys[i-2][j+3]!='1'){E.easys[i-2][j+3]='2';}
				if(E.easys[i-2][j]!='M'&&E.easys[i-2][j]!='1'){E.easys[i-2][j]='2';}
				if(E.easys[i-2][j+2]!='M'&&E.easys[i-2][j+2]!='1'){E.easys[i-2][j-2]='2';}
				if(E.easys[i][j-2]!='M'&&E.easys[i][j-2]!='1'){E.easys[i][j-2]='2';}
				if(E.easys[i][j+2]!='M'&&E.easys[i][j+2]!='1'){E.easys[i][j+2]='2';}
				if(E.easys[i+2][j-2]!='M'&&E.easys[i+2][j-2]!='1'){E.easys[i+2][j+2]='2';}
				if(E.easys[i+2][j]!='M'&&E.easys[i+2][j]!='1'){E.easys[i+2][j]='2';}
				if(E.easys[i+2][j+2]!='M'&&E.easys[i+2][j+2]!='1'){E.easys[i+2][j+2]='2';}
				if(E.easys[i+2][j+3]!='M'&&E.easys[i+2][j+3]!='1'){E.easys[i+2][j+3]='2';}
				if(E.easys[i+2][j-3]!='M'&&E.easys[i+2][j-3]!='1'){E.easys[i+2][j-3]='2';}
			}
			if(E.easys[i][j]=='*'){E.easys[i][j]='3';}
		}
	}
	/*
	a=0;
	b=0;
	for(i=0,j=0;i<9;i++)
	{
		if(b==0){printf("  ");b++;}
		while(a<9)
		{
			printf("  %d  ",a);
			a++;
		}
		if(a==9){printf("\n\n");a++;}
		printf("%d ",i);
		for(j=0;j<9;j++)
		{
			printf(" |%c| ",E.easys[i][j]);
		}
		printf("     %d\n\n",i);
	}
	*/
	for(i=0;i<9;i++){for(j=0;j<9;j++){E.easyc[i][j]=' ';}}//clean array
	for(i=0;i<9;i++){for(j=0;j<9;j++){if(E.easys[i][j]==' '){E.easys[i][j]='3';}}}
	c=0;
	start=clock();//start the timer for the game
	while(E.easyc[i][j]!='M')
	{
		a=0;
		b=0;
		for(i=0,j=0;i<9;i++)
		{
			if(b==0){printf("  ");b++;}
			while(a<9)
			{
				printf("  %d  ",a);
				a++;
			}
			if(a==9){printf("\n\n");a++;}
			printf("%d ",i);
			for(j=0;j<9;j++)
			{
				printf(" |%c| ",E.easyc[i][j]);
			}
			printf("     %d\n\n",i);
		}
		printf("Please enter a y and x co-ordinate\r\n");
		scanf("%d%*c %d%*c",&x,&y);
		if(x<0||y<0||x>9||y>9){printf("wrong co-ordinates , please try again\r\n");wait_for_user();}
		else
		{
			
			E.easyc[x][y]=E.easys[x][y];
			if(E.easyc[x][y]=='M')
			{
				printf("YOU HIT A MINE AAAAHHHHH\r\n");
				a=0;
				b=0;
				for(i=0,j=0;i<9;i++)
				{
					if(b==0){printf("  ");b++;}
					while(a<9)
					{
						printf("  %d  ",a);
						a++;
					}
					if(a==9){printf("\n\n");a++;}
					printf("%d ",i);
					for(j=0;j<9;j++)
					{
						if(E.easys[i][j]=='M'){printf(" |%c| ",E.easys[i][j]);}
							else
								printf(" | | ",E.easys[i][j]);
					}
					printf("     %d\n\n",i);
				}
				break;
			}
			else
			{
				if(E.easys[x-1][y-1]!='M'){E.easyc[x-1][y-1]=E.easys[x-1][y-1];}
				if(E.easys[x-1][y]!='M'){E.easyc[x-1][y]=E.easys[x-1][y];}
				if(E.easys[x-1][y-1]!='M'){E.easyc[x-1][y-1]=E.easys[x-1][y-1];}
				if(E.easys[x-1][y+1]!='M'){E.easyc[x-1][y+1]=E.easys[x-1][y+1];}
				if(E.easys[x][y-1]!='M'){E.easyc[x][y-1]=E.easys[x][y-1];}
				if(E.easys[x][y+1]!='M'){E.easyc[x][y+1]=E.easys[x][y+1];}
				if(E.easys[x+1][y-1]!='M'){E.easyc[x+1][y-1]=E.easys[x+1][y-1];}
				if(E.easys[x+1][y]!='M'){E.easyc[x+1][y]=E.easys[x+1][y];}
				if(E.easys[x+1][y+1]!='M'){E.easyc[x+1][y+1]=E.easys[x+1][y+1];}
				c++;
				
				for(i=0,e=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						if(E.easyc[i][j]!=' '){e++;}
						else
							continue;
					}
				}
				//ERROR
				if(e>65){break;printf("Congratulations,You've Won\r\n");}
				else
					continue;
				
				wait_for_user();
				
			}
		
		}
		
	}
	printf("Took %f seconds\n", ((double)clock()-start)/CLOCKS_PER_SEC);//print the number of seconds which is worked out as an end variable-start/number of 
																		//clock cycles since execution
	wait_for_user();
	printf("Do you want to play again?\nY or N\r\n");
	scanf("%s",&answer);
	if(answer[0]=='y'||answer[0]=='Y'){GAME();}
	else
		{end_all();}

}

void MEDIUM()//medium game function, steps are clean , populate and final game loop
{
	for(i=0;i<16;i++){for(j=0;j<16;j++){M.mediums[i][j]='*';}}//clean array
	c=0;
	for(i=0,j=0;c<40&&i<16;i++)//populate the minefield
	{
		a=0;
		for(j=0;j<16;j++)
		{
			if(j==(rand()%16)&&M.mediums[i][j]!='M'&&j<8&&a<6||i==(rand()%16)&&M.mediums[i][j]!='M'&&j<8&&a<6)//no more than 6 mines per line
			{
				M.mediums[i][j]='M';
				//printf("c=%d\r\n",c);
				a++;
				c++;
			}
			if(j==(rand()%16)&&M.mediums[i][j]!='M'&&j>=8&&a<6||i==(rand()%16)&&M.mediums[i][j]!='M'&&j>=8&&a<6)//no more than 6 mines per line
			{
				M.mediums[i][j]='M';
				//printf("c=%d\r\n",c);
				a++;
				c++;
			}
			if(M.mediums[i][j]!='M'){M.mediums[i][j]='*';}
		}
		if(i==16){i=0;}
	}
	
	a=0;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(M.mediums[i][j]=='M'){a++;}
			else
				continue;
		}
	}
	printf("%d mines are in the array\r\n",a);
	
	for(i=0,j=0;i<40;i++)//populate the proximity bounds
	{
		for(j=0;j<40;j++)
		{
			if(M.mediums[i][j]=='M')
			{
				if(M.mediums[i-1][j-1]!='M'){M.mediums[i-1][j-1]='1';}
				if(M.mediums[i-1][j]!='M'){M.mediums[i-1][j]='1';}
				if(M.mediums[i-1][j+1]!='M'){M.mediums[i-1][j+1]='1';}
				if(M.mediums[i][j-1]!='M'){M.mediums[i][j-1]='1';}
				if(M.mediums[i][j+1]!='M'){M.mediums[i][j+1]='1';}
				if(M.mediums[i+1][j-1]!='M'){M.mediums[i+1][j-1]='1';}
				if(M.mediums[i+1][j]!='M'){M.mediums[i+1][j]='1';}
				if(M.mediums[i+1][j+1]!='M'){M.mediums[i+1][j+1]='1';}
			}
		}
	}
	for(i=0,j=0;i<40;i++)//populate the proximity bounds
	{
		for(j=0;j<40;j++)
		{
			if(M.mediums[i][j]=='M')
			{
				if(M.mediums[i-2][j-2]!='M'&&M.mediums[i-2][j-2]!='1'){M.mediums[i-2][j-2]='2';}
				if(M.mediums[i-2][j]!='M'&&M.mediums[i-2][j]!='1'){M.mediums[i-2][j]='2';}
				if(M.mediums[i-2][j+2]!='M'&&M.mediums[i-2][j+2]!='1'){M.mediums[i-2][j-2]='2';}
				if(M.mediums[i][j-2]!='M'&&M.mediums[i][j-2]!='1'){M.mediums[i][j-2]='2';}
				if(M.mediums[i][j+2]!='M'&&M.mediums[i][j+2]!='1'){M.mediums[i][j+2]='2';}
				if(M.mediums[i+2][j-2]!='M'&&M.mediums[i+2][j-2]!='1'){M.mediums[i+2][j+2]='2';}
				if(M.mediums[i+2][j]!='M'&&M.mediums[i+2][j]!='1'){M.mediums[i+2][j]='2';}
				if(M.mediums[i+2][j+2]!='M'&&M.mediums[i+2][j+2]!='1'){M.mediums[i+2][j+2]='2';}
			}
			if(M.mediums[i][j]=='*'){M.mediums[i][j]='3';}
		}
	}
	/*
	a=0;
	b=0;
	for(i=0;i<16;i++)
	{
		if(b==0){printf("   ");b++;}
		while(a<10)
		{
			printf(" %d ",a);
			a++;
		}
		while(a<16)
		{
			printf("%d ",a);
			a++;
		}
		if(a==16){printf("\n");a++;}
		if(i<=9){printf("%d  ",i);}
		if(i>9){printf("%d ",i);}
		for(j=0;j<16;j++)
		{
			printf("|%c|",M.mediums[i][j]);
		}
		printf("  %d\n",i);
	}
	*/
	for(i=0;i<16;i++){for(j=0;j<16;j++){M.mediumc[i][j]=' ';}}//clean array
	for(i=0;i<16;i++){for(j=0;j<16;j++){if(M.mediums[i][j]==' '){M.mediums[i][j]='3';}}}//check if any spaces are still blank
	c=0;
	start=clock();//start the timer for the game
	while(M.mediumc[i][j]!='M')
	{
			a=0;
			b=0;
			for(i=0;i<16;i++)
			{
				if(b==0){printf("   ");b++;}
				while(a<10)
				{
					printf(" %d ",a);
					a++;
				}
				while(a<16)
				{
					printf("%d ",a);
					a++;
				}
				if(a==16){printf("\n");a++;}
				if(i<=9){printf("%d  ",i);}
				if(i>9){printf("%d ",i);}
				for(j=0;j<16;j++)
				{
					printf("|%c|",M.mediumc[i][j]);
				}
				printf("  %d\n",i);
			}

			printf("Please enter a y and x co-ordinate\r\n");
			scanf("%d%*c %d%*c",&x,&y);
			if(x<0||y<0||x>16||y>16){printf("wrong co-ordinates , please try again\r\n");wait_for_user();}

			M.mediumc[x][y]=M.mediums[x][y];
			if(M.mediumc[x][y]=='M')
			{
				printf("YOU HIT A MINE AAAAHHHHH\r\n");
				a=0;
				b=0;
				for(i=0,j=0;i<16;i++)
				{
					if(b==0){printf("    ");b++;}
					while(a<9)
					{
						printf(" %d ",a);
						a++;
					}
					while(a<16)
					{
						printf("%d ",a);
						a++;
					}
					if(a==16){printf("\n");a++;}
					if(i<10){printf(" %d ",i);}
					if(i>9&&i<16){printf("%d ",i);}
					for(j=0;j<16;j++)
					{
						if(M.mediums[i][j]=='M'){printf("|%c|",M.mediums[i][j]);}
							else
								printf("| |",M.mediums[i][j]);
					}
					printf("   %d\n",i);
				}
				break;
			}
			else
			{
				if(M.mediums[x-1][y-1]!='M'){M.mediumc[x-1][y-1]=M.mediums[x-1][y-1];}
				if(M.mediums[x-1][y]!='M'){M.mediumc[x-1][y]=M.mediums[x-1][y];}
				if(M.mediums[x-1][y+1]!='M'){M.mediumc[x-1][y+1]=M.mediums[x-1][y+1];}
				if(M.mediums[x][y-1]!='M'){M.mediumc[x][y-1]=M.mediums[x][y-1];}
				if(M.mediums[x][y+1]!='M'){M.mediumc[x][y+1]=M.mediums[x][y+1];}
				if(M.mediums[x+1][y-1]!='M'){M.mediumc[x+1][y-1]=M.mediums[x+1][y-1];}
				if(M.mediums[x+1][y]!='M'){M.mediumc[x+1][y]=M.mediums[x+1][y];}
				if(M.mediums[x+1][y+1]!='M'){M.mediumc[x+1][y+1]=M.mediums[x+1][y+1];}
				
				for(i=0,e=0;i<16;i++)
				{
					for(j=0;j<16;j++)
					{
						if(M.mediumc[i][j]!=' ')
						{e++;}
					}
				}
				if(e>210){break;printf("Congratulations,You've Won\r\n");}//16x16=256-40=216 so wait until about 210 are gone to say they've won
				wait_for_user();
				c++;
				
			}
	}
	printf("Took %f seconds\n", ((double)clock()-start)/CLOCKS_PER_SEC);
	wait_for_user();
	printf("Do you want to play again\nY or N\r\n");
	scanf("%s",answer);
	if(answer[0]=='y'||answer[0]=='Y'){GAME();}
	else
		{end_all();}
}

void HARD()//hard game function, steps are clean , populate and final game loop
{
	for(i=0;i<30;i++){for(j=0;j<16;j++){H.hards[i][j]='*';H.hardc[i][j]=' ';}}
	c=0;
	//ERROR
	for(i=0,j=0;c<100;i++)//populate the minefield
	{
		a=0;
		if(i==(rand()%30)&&H.hards[i][j]!='M'&&c<=50&&a<4)
		{
			
			for(j=0;j<16;j++)
			{
				
					if(j==(rand()%16)&&j<=8&&H.hards[i][j]!='M')
					{
						H.hards[i][j]='M';
						//printf("first half %d\r\n",c,d);
						c++;
						a++;
					}
			}
		}
		if(i==(rand()%30)&&H.hards[i][j]!='M'&&c>=50&&a<5)
		{
			
			for(j=0;j<16;j++)
			{
				if(j==(rand()%16)&&j>=7&&H.hards[i][j]!='M')
				{
					H.hards[i][j]='M';
					//printf("second half %d\r\n",c,d);
					c++;
					a++;
				}
			}
		}
		if(H.hards[i][j]!='M'){H.hards[i][j]='*';}
		if(i==29){i=0;}
	}
	//ERROR
	
	a=0;
	for(i=0;i<30;i++)
	{
		for(j=0;j<16;j++)
		{
			if(H.hards[i][j]=='M'){a++;}
			else 
				continue;
		}
	}
	printf("%d mines are in the array\r\n",a);
	
	for(i=0,j=0;i<40;i++)//populate the first level proximity bounds 
	{
		for(j=0;j<40;j++)
		{
			if(H.hards[i][j]=='M')
			{
				if(H.hards[i-1][j-1]!='M'){H.hards[i-1][j-1]='1';}
				if(H.hards[i-1][j]!='M'){H.hards[i-1][j]='1';}
				if(H.hards[i-1][j+1]!='M'){H.hards[i-1][j+1]='1';}
				if(H.hards[i][j-1]!='M'){H.hards[i][j-1]='1';}
				if(H.hards[i][j+1]!='M'){H.hards[i][j+1]='1';}
				if(H.hards[i+1][j-1]!='M'){H.hards[i+1][j-1]='1';}
				if(H.hards[i+1][j]!='M'){H.hards[i+1][j]='1';}
				if(H.hards[i+1][j+1]!='M'){H.hards[i+1][j+1]='1';}
			}
		}
	}
	for(i=0,j=0;i<40;i++)//populate the second level proximity bounds
	{
		for(j=0;j<40;j++)
		{
			if(H.hards[i][j]=='M')
			{
				if(H.hards[i-2][j-2]!='M'&&H.hards[i-2][j-2]!='1'){H.hards[i-2][j-2]='2';}
				if(H.hards[i-2][j]!='M'&&H.hards[i-2][j]!='1'){H.hards[i-2][j]='2';}
				if(H.hards[i-2][j+2]!='M'&&H.hards[i-2][j+2]!='1'){H.hards[i-2][j+2]='2';}
				if(H.hards[i][j-2]!='M'&&H.hards[i][j-2]!='1'){H.hards[i][j-2]='2';}
				if(H.hards[i][j+2]!='M'&&H.hards[i][j+2]!='1'){H.hards[i][j+2]='2';}
				if(H.hards[i+2][j-2]!='M'&&H.hards[i+2][j-2]!='1'){H.hards[i+2][j-2]='2';}
				if(H.hards[i+2][j]!='M'&&H.hards[i+2][j]!='1'){H.hards[i+2][j]='2';}
				if(H.hards[i+2][j+2]!='M'&&H.hards[i+2][j+2]!='1'){H.hards[i+2][j+2]='2';}
			}
			if(H.hards[i][j]=='*'){H.hards[i][j]='3';}
		}
	}
	//ERROR
	/*
	a=0;
	b=0;
	for(i=0;i<30;i++)
	{
		if(b==0){printf("    ");b++;}
		while(a<10)
		{
			printf("%d ",a);
			a++;
		}
		while(a<16)
		{
			printf("%d ",a);
			a++;
		}
		if(a==16){printf("\n");}
		if(i<=9){printf("%d  ",i);}
		if(i>9){printf("%d ",i);}
		for(j=0;j<16;j++)
		{
			printf("|%c|",H.hards[i][j]);
		}
		printf("  %d\n",i);
	}
	*/
	
	for(i=0;i<30;i++){for(j=0;j<16;j++){H.hardc[i][j]='\0';}}//clean array
	for(i=0;i<16;i++){for(j=0;j<16;j++){if(H.hards[i][j]==' '){H.hards[i][j]='3';}}}//check if any spaces are still blank
	c=0;
	//ERROR
	start = clock();
	while(H.hardc[i][j]!='M')
	{
		a=0;
		b=0;
		for(i=0;i<30;i++)
		{
			if(b==0){printf("   ");b++;}
			while(a<10)
			{
				printf(" %d ",a);
				a++;
			}
			while(a<16)
			{
				printf("%d ",a);
				a++;
			}
			if(a==16){printf("\n");a++;}
			if(i<=9){printf("%d  ",i);}
			if(i>9){printf("%d ",i);}
			for(j=0;j<16;j++)
			{
				printf("|%c|",H.hardc[i][j]);
			}
			printf("  %d\n",i);
		}
		
			x='\0';
			y='\0';
			printf("Please enter a y and x co-ordinate\r\n");
			scanf("%d%*c %d%*c",&x,&y);
			if(x<0||y<0||x>30||y>16){printf("wrong co-ordinates , please try again\r\n");wait_for_user();}
			else
			{
				H.hardc[x][y]=H.hards[x][y];
				if(H.hardc[x][y]=='M')
				{
					printf("YOU HIT A MINE AAAAHHHHH\r\n");
					a=0;
					b=0;
					for(i=0,j=0;i<30;i++)
					{
						if(b==0){printf("  ");b++;}
						while(a<9)
						{
							printf(" %d ",a);
							a++;
						}
						while(a<16)
						{
							printf(" %d ",a);
							a++;
						}
						if(a==16){printf("\n");a++;}
						if(i<10){printf("%d ",i);}
						if(i>9){printf("%d",i);}
						for(j=0;j<16;j++)
						{
							if(H.hards[i][j]=='M'){printf("|%c|",H.hards[i][j]);}
							else
								printf("| |",H.hards[i][j]);
						}
						printf("   %d\n",i);
					}
					break;
				}
				if(H.hardc[x][y]!='M')
				{
					if(H.hards[x-1][y-1]!='M'){H.hardc[x-1][y-1]=H.hards[x-1][y-1];}
					if(H.hards[x-1][y]!='M'){H.hardc[x-1][y]=H.hards[x-1][y];}
					if(H.hards[x-1][y+1]!='M'){H.hardc[x-1][y-1]=H.hards[x-1][y+1];}
					if(H.hards[x][y-1]!='M'){H.hardc[x][y-1]=H.hards[x][y-1];}
					if(H.hards[x][y+1]!='M'){H.hardc[x][y+1]=H.hards[x][y+1];}
					if(H.hards[x+1][y-1]!='M'){H.hardc[x+1][y+1]=H.hards[x+1][y-1];}
					if(H.hards[x+1][y]!='M'){H.hardc[x+1][y]=H.hards[x+1][y];}
					if(H.hards[x+1][y+1]!='M'){H.hardc[x+1][y+1]=H.hards[x+1][y+1];}
					
					for(i=0,e=0;i<30;i++)
					{
						for(j=0;j<16;j++)
						{
							if(H.hardc[i][j]!=' ')
							{e++;}
						}
					}
					if(e<10){break;printf("Congratulations,You've Won\r\n");wait_for_user();}//slightly different , the game ends when the number of spaces in
																							 //guess array are less than 10 , which is 480-99=381-10=371 spaces
					else
						continue;
				}
			}
	}
	//ERROR
	printf("Took %f seconds\n", ((double)clock()-start)/CLOCKS_PER_SEC);
	wait_for_user();
	printf("Do you want to play again?\nY or N\r\n");
	scanf("%s",answer);
	if(answer[0]=='y'||answer[0]=='Y'){GAME();}
	else
		{end_all();}
}

void GAME()//function for asking what difficulty the user wants
{
	srand(time(NULL));
	clear_screen();
	user_choice1=0;
	printf("Please enter a number for the corresponding difficulty setting\r\n");
	printf("1.Easy 9x9 and 10 mines\r\n");
	printf("2.Medium 16x16 and 40 mines\r\n");
	printf("3.Hard 16x30 and 99mines\r\n");
	printf("4.Quit\r\n");
	printf("Please enter your choice\r\n");
	scanf("%d%*c",&user_choice1);
	//dummy=getchar();
	if(user_choice1==1){	  EASY();	}
	if(user_choice1==2){	  MEDIUM();	}
	if(user_choice1==3){	  HARD();	}
	if(user_choice1==4){	  end_all();}
	if(user_choice1!=1&&user_choice1!=2&&user_choice1!=3&&user_choice1!=4)
	{
		printf("Please enter a valid choice\r\n");
		wait_for_user();
		GAME();
	}

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
	for(i=0;i<40;i++)
	{printf("\n");}
}

void end_all()//d game function
{
	clear_screen();
	printf("Game is Over..GoodBye\r\n");
	printf("Thank you for playing Mine Sweeper V1.0\r\n");
	exit(0);
}

void author()//info about the author
{
	clear_screen();
	printf("\nAuthor is Evan O'Keeffe\r\n");
	printf("Started in March 3rd 2011\r\n");
	printf("Project 3\r\n");
	printf("Done as part of software engineering 1 2011\r\n");
	printf("Studt of University College of Dublin\r\n");
	wait_for_user();
	options();
}

void help()//simple help screen so people know how the game works
{
	clear_screen();
	printf("So the whole point of the game is to guess\r\n");
	printf("where the mines are in the field and avoid them \r\n");
	printf("if the proximity of the mine is very close\r\n");
	printf("1 will be in the square\r\n");
	printf("2 will be in the square\r\n");
	printf("if the mine is not near then B for blank will show in the box\r\n");
	printf("But if your unlucky then you'll have hit the mine and blown up\r\n");
	wait_for_user();
	options();
}

void options()//show the options
{
	clear_screen();
	printf("Mine Sweeper version 1.0\r\n");
	printf("Please input a number for the option\r\n");
	printf("1.Play Mine Sweeper\r\n");
	printf("2.Help\r\n");
	printf("3.Author\r\n");
	printf("4.Exit\r\n");
	user_choice=0;
	scanf("%d%*c",&user_choice);
	//dummy=getchar();
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