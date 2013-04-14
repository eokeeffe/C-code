/*
	Tier 1 : Part 10	:	Question 3
	
*/
#include<stdio.h>
#include<string.h>

struct Data
{
	char student_name[50];
	int id_number;
	int year_start;
	int year_end;
	float grade_point_average;
}d;

int main()
{
	printf("Please enter a name\r\n");
	gets(d.student_name);
	
	printf("Please enter an id number\r\n");
	scanf("%d%*c",&d.id_number);
	
	printf("Please enter the starting year e.g 2011 \r\n");
	scanf("%d%*c",&d.year_start);
	
	printf("Please enter the ending date e.g 2015 \r\n");
	scanf("%d%*c",&d.year_end);
	
	printf("Please enter the GPA for the student \r\n");
	scanf("%f%*c",&d.grade_point_average);
	
		
	printf("Student Name:%s\r\n",d.student_name);
	printf("Student I.D Number:%d \r\n",d.id_number);
	printf("The student started in the year %d\r\n",d.year_start);
	printf("The student left in the year %d\r\n",d.year_end);
	printf("The student GPA was %f\r\n",d.grade_point_average);
	
	return 0;
}