/*
	Tier 1 : Part 10	:	Question 2
	
*/
#include<stdio.h>
#include<string.h>

struct Data
{
	char student_name[50];
	int id_number;
}d;

int main()
{
	strcpy(d.student_name,"John Smith");
	d.id_number = 12345678;
	
	printf("Student Name:%s\r\n",d.student_name);
	printf("Student I.D Number:%d \r\n",d.id_number);
	return 0;
}