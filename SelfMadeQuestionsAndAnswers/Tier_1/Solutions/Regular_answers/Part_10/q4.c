/*
	Tier 1 : Part 10	:	Question 4
	
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
}student_1,student_2;

int main()
{
	printf("Please enter a name for student 1\r\n");
	gets(student_1.student_name);
	
	printf("Please enter an id number for student 1\r\n");
	scanf("%d%*c",&student_1.id_number);
	
	printf("Please enter the starting year e.g 2011 \r\n");
	scanf("%d%*c",&student_1.year_start);
	
	printf("Please enter the ending date e.g 2015 \r\n");
	scanf("%d%*c",&student_1.year_end);
	
	printf("Please enter the GPA for the student 1 \r\n");
	scanf("%f%*c",&student_1.grade_point_average);
	
	printf("Please enter a name for student 2\r\n");
	gets(student_2.student_name);
	
	printf("Please enter an id number for student 2\r\n");
	scanf("%d%*c",&student_2.id_number);
	
	printf("Please enter the starting year e.g 2011 \r\n");
	scanf("%d%*c",&student_2.year_start);
	
	printf("Please enter the ending date e.g 2015 \r\n");
	scanf("%d%*c",&student_2.year_end);
	
	printf("Please enter the GPA for the student 2 \r\n");
	scanf("%f%*c",&student_2.grade_point_average);
	
		
	printf("Student Name:%s\r\n",student_1.student_name);
	printf("Student I.D Number:%d \r\n",student_1.id_number);
	printf("The student started in the year %d\r\n",student_1.year_start);
	printf("The student left in the year %d\r\n",student_1.year_end);
	printf("The student GPA was %f\r\n",student_1.grade_point_average);	
	
	printf("\r\n");
	
	printf("Student Name:%s\r\n",student_2.student_name);
	printf("Student I.D Number:%d \r\n",student_2.id_number);
	printf("The student started in the year %d\r\n",student_2.year_start);
	printf("The student left in the year %d\r\n",student_2.year_end);
	printf("The student GPA was %f\r\n",student_2.grade_point_average);
	
	return 0;
}