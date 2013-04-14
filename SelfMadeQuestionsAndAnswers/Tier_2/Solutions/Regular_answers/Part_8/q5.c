/*
	Tier 2 : Part 8	:	Question 5
	
	C is made using the struct system , in other languages they work nearly the exact same as structs
	only the structs are called classes and have a few differences but in essence work almost the same
	
*/
#include "myheader_q5.h"

int main()
{
	strcpy(student_1.student_name,"Evan O'Keeffe");
	strcpy(student_1.degree_name,"B.Sc Computer Science");
	student_1.student_number = 12344289;
	
	printf("Student name:%s\r\n",student_1.student_name);
	printf("Course name:%s\r\n",student_1.degree_name);
	printf("Student number:%d\r\n",student_1.student_number);
	return 0;
}