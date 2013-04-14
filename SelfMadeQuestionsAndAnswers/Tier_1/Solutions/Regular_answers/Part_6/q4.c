/*
	Tier 1 : Part 6	:	Question 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char guessing_password_string[20] , password_string[20];
	char user_name_string[20], guessing_user_name_string[20], catch_the_return_feed;
	int clean_array , number_of_wrong_guesses = 0 , number_of_wrong_tries = 3;
	
	//clean the arrays
	for(clean_array = 0; clean_array < 20; clean_array++)
	{
		guessing_user_name_string[clean_array]='\0';
		user_name_string[clean_array]='\0';
		guessing_password_string[clean_array]='\0';
		password_string[clean_array]='\0';
	}
	
	printf("What is the right word ?\r\n");
	
	strcpy(user_name_string,"user");
	strcpy(password_string,"password");
	
	while( number_of_wrong_guesses < number_of_wrong_tries)
	{
		printf("Please enter the User name\r\n");
		scanf("%s",&guessing_user_name_string);
		catch_the_return_feed = getchar();
		
		printf("Please enter the password\r\n");
		scanf("%s",&guessing_password_string);
		catch_the_return_feed = getchar();
		
		if(strcmp(password_string,guessing_password_string) == 0 && strcmp(user_name_string,guessing_user_name_string) == 0)
		{
			printf("Correct Login , Welcome %s \r\n",guessing_user_name_string); 
			exit(0);
		}
		
		else if(strcmp(user_name_string,guessing_user_name_string) == 0 && strcmp(password_string,guessing_password_string) != 0)
		{
			printf("Password doesn't match the User name , please try again\r\n");
			number_of_wrong_guesses++;
		}
			
		else 
		{	
			printf("User name or password are incorrect , please enter them again\r\n");
			number_of_wrong_guesses++;
		}
	}

	if(number_of_wrong_guesses == 3)
	{
		printf("You have exceeded the maxiumum number of tries , program will now terminate\r\n");
	}
	return 0;
}