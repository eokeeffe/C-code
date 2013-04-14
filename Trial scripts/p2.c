/*
	Using pointers to functions for CMD operations
*/
#include<stdio.h>
#include<stdlib.h>

void (*file_cmd[])(void)={
							new_cmd,
							open_cmd,
							close_cmd,
							close_all_cmd,
							save_cmd,
						    save_as_cmd,
							save_all_cmd,
							print_cmd,
							exit_cmd
						 };

int main()
{
	int choice;
	printf("Please enter a number for the function below\r\n");
	printf(" new cmd console\r\n");
	printf(" open cmd console\r\n");
	printf(" close cmd\r\n");
	printf(" close all cmds\r\n");
	printf(" sae cmd\r\n");
	printf(" save as cmd\r\n");
	printf(" save all cmds\r\n");
	printf(" print the cmd\r\n");
	printf(" exit cmd\r\n");
	scanf("%d",&choice);
	
	(*file_cmd[choice]);

	return 0;
}