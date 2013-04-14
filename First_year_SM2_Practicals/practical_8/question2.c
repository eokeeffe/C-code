/*Evan O'Keeffe
  10324289
  practical8 question2
*/
#include<stdio.h>

A.	enum compass {north = 2, south, east = 1, west};

//the values returned by this will be 2,1,1,2

B.	enum compass move_1 = south, move_2 = north;

//move_1=3 and move_2=2

C.	int score = 0;
	enum compass move;
	...
	switch (move) 
	{
		case north: score += 10;
		break;
		case south: score += 20;
		break;
		case east: score += 30;
		break;
		case west: score += 40;
		break;
		default : printf ("ERROR - Please t r y again\n") ;
	}

//if the statement move is north score=10
//if the statement move is south score=20
//if the statement move is east score=30
//if the statement move is west score=40
//if the statement move is none of the above print error
