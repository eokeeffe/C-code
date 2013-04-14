/*
	Tier 3 : Part 2	:	Question 9
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 20

struct database
{
	char part_name[50];
	char part_section[50];
	int part_number;
	float part_price;
	double part_rating;
}var;

struct database list[ARRAY_SIZE];

int get_information_from_file()
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("part_database.txt","r");
	
	if(FILE_HANDLE == NULL)
	{
		printf("\r\n");
		exit(0);
	}
	else
	{
		int loop_counter;
	
		for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
		{
			fscanf(FILE_HANDLE,"%s",&list[loop_counter].part_name);
			fscanf(FILE_HANDLE,"%s",&list[loop_counter].part_section);
			fscanf(FILE_HANDLE,"%d",&list[loop_counter].part_number);
			fscanf(FILE_HANDLE,"%f",&list[loop_counter].part_price);
			fscanf(FILE_HANDLE,"%lf",&list[loop_counter].part_rating);
		}
	}
	close(FILE_HANDLE);
	return 0;
}

int print_database()
{
	int loop_counter;
	
	for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
	{
		if(list[loop_counter].part_number != 0)
		{
			printf("Part Name    : %s \r\n",list[loop_counter].part_name);
			printf("Part section : %s \r\n",list[loop_counter].part_section);
			printf("Part number  : %d \r\n",list[loop_counter].part_number);
			printf("Price        : %.2f \r\n",list[loop_counter].part_price);
			printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
			
			wait_for_user();
		}
	}
	
	return 0;
}

int search_database()
{
	int search_type;
	
	printf("Please enter a number for the search type\r\n");
	printf("1. Part Name \r\n");
	printf("2. Part Section \r\n");
	printf("3. Part Number \r\n");
	printf("4. Part Price range\r\n");
	printf("5. Part Rating range\r\n");
	printf("6. Back to Menu \r\n");
	
	while( scanf("%d",&search_type) != 1 )
	{
		fflush(stdin);
	}
	
	switch( search_type )
	{	
		case 1: 
		{	
			char part_name_search[50];
			
			printf("Please enter the name of the part your searching for\r\n");
			fgets(part_name_search,50,stdin);
			
			int loop_counter;
	
			for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
			{
				if(strcmp(part_name_search,list[loop_counter].part_name)==0)
				{
					printf("Part Name    : %s \r\n",list[loop_counter].part_name);
					printf("Part section : %s \r\n",list[loop_counter].part_section);
					printf("Part number  : %d \r\n",list[loop_counter].part_number);
					printf("Price        : %.2f \r\n",list[loop_counter].part_price);
					printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
				}
			}
			
			wait_for_user();
			menu();
			
			break;
		}
		case 2: 
		{	
			char section_search[50];
			
			printf("Please enter the part section your looking for\r\n");
			fgets(section_search,50,stdin);
			
			int loop_counter;
	
			for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
			{
				if(strcmp(section_search,list[loop_counter].part_section)==0)
				{
					printf("Part Name    : %s \r\n",list[loop_counter].part_name);
					printf("Part section : %s \r\n",list[loop_counter].part_section);
					printf("Part number  : %d \r\n",list[loop_counter].part_number);
					printf("Price        : %.2f \r\n",list[loop_counter].part_price);
					printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
				}
			}
			
			wait_for_user();
			menu();
			
			break;
		}
		case 3: 
		{	
			int part_search;
			
			printf("Please enter the part number you wish to search for\r\n");
			
			while( scanf("%d",&part_search) != 1 )
			{
				fflush(stdin);
			}
			
			int loop_counter;
	
			for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
			{
				if(part_search == list[loop_counter].part_number)
				{
					printf("Part Name    : %s \r\n",list[loop_counter].part_name);
					printf("Part section : %s \r\n",list[loop_counter].part_section);
					printf("Part number  : %d \r\n",list[loop_counter].part_number);
					printf("Price        : %.2f \r\n",list[loop_counter].part_price);
					printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
				}
			}
			
			wait_for_user();
			menu();
			
			break;
		}
		case 4: 
		{	
			int price_max , price_min;
			
			printf("Please enter the min and max price range your looking for\r\n");
			
			while( scanf("%d %d",&price_max,&price_min) != 2 )
			{
				fflush(stdin);
			}
			
			int loop_counter;
	
			for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
			{
				if(list[loop_counter].part_price <= price_max && list[loop_counter].part_price >= price_min)
				{
					printf("Part Name    : %s \r\n",list[loop_counter].part_name);
					printf("Part section : %s \r\n",list[loop_counter].part_section);
					printf("Part number  : %d \r\n",list[loop_counter].part_number);
					printf("Price        : %.2f \r\n",list[loop_counter].part_price);
					printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
				}
			}
			
			wait_for_user();
			menu();
			
			break;
		}
		case 5: 
		{	
			int rating_max,rating_min;
			
			printf("Please enter the min and max rating range your looking for\r\n");
			
			while( scanf("%d %d",&rating_max,&rating_min) != 2 )
			{
				fflush(stdin);
			}
			
			int loop_counter;
	
			for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
			{
				if(list[loop_counter].part_rating <= rating_max && list[loop_counter].part_rating >= rating_min)
				{
					printf("Part Name    : %s \r\n",list[loop_counter].part_name);
					printf("Part section : %s \r\n",list[loop_counter].part_section);
					printf("Part number  : %d \r\n",list[loop_counter].part_number);
					printf("Price        : %.2f \r\n",list[loop_counter].part_price);
					printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
				}
			}
			
			wait_for_user();
			menu();
			
			break;
		}
		default:
		{
			wait_for_user();
			menu();
			break;
		}
	}
	
	wait_for_user();
	menu();
	
	return 0;
}

int exit_program()
{
	printf("Exiting Database\r\n");
	exit(0);
	return 0;
}

int wait_for_user()
{
	char capture_return_key;
	printf("press enter\r\n");
	capture_return_key = getchar();
	
	return 0;
}

int update_database()
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("part_database.txt","w");
	
	if(FILE_HANDLE == NULL)
	{
		printf("\r\n");
		exit(0);
	}
	else
	{
		int loop_counter;
	
		for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
		{
			if(list[loop_counter].part_number != 0)
			{
				fprintf(FILE_HANDLE,"%s ",list[loop_counter].part_name);
				fprintf(FILE_HANDLE,"%s ",list[loop_counter].part_section);
				fprintf(FILE_HANDLE,"%d ",list[loop_counter].part_number);
				fprintf(FILE_HANDLE,"%.2f ",list[loop_counter].part_price);
				fprintf(FILE_HANDLE,"%.2lf ",list[loop_counter].part_rating);
				fprintf(FILE_HANDLE,"%s","\r\n");
			}
		}
	}
	close(FILE_HANDLE);
	return 0;
}

int add_parts_to_database()
{
	int loop_counter,new_part_place;
	
	for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
	{
		if(list[loop_counter].part_number == 0)
		{
			new_part_place = loop_counter;
			break;
		}
	}
	
	printf("Please enter the part name \r\n");
	fgets(list[new_part_place].part_name,50,stdin);
	
	printf("Please enter a part section for %s \r\n",list[new_part_place].part_name);
	fgets(list[new_part_place].part_section,50,stdin);
	
	printf("Please enter the part number\r\n");
	while( scanf("%d",&list[new_part_place].part_number) != 1)
	{
		fflush(stdin);
	}
	
	printf("Please enter the part price\r\n");
	while( scanf("%f",&list[new_part_place].part_price) != 1)
	{
		fflush(stdin);
	}
	
	printf("Please enter the part rating\r\n");
	while( scanf("%lf",&list[new_part_place].part_rating) != 1)
	{
		fflush(stdin);
	}
	
	update_database();
	
	wait_for_user();
	menu();
	return 0;
}

int remove_parts_from_database()
{
	int remove_part;

	printf("Please enter the part number or a negative number to exit\r\n");
	
	while( scanf("%d",&remove_part) != 1)
	{
		fflush(stdin);
	}
	
	if(remove_part >= 0)
	{
		int loop_counter;
		
		for(loop_counter=0;loop_counter<ARRAY_SIZE;loop_counter++)
		{
			if(list[loop_counter].part_number == remove_part)
			{
				strcpy(list[loop_counter].part_name , "" );
				strcpy(list[loop_counter].part_section , "");
				list[loop_counter].part_number = 0   ;
				list[loop_counter].part_price = 0.0  ;
				list[loop_counter].part_rating = 0.0 ;
			}
		}
		
		update_database();
		menu();
	}
	else
	{
		menu();
	}
	return 0;
}

int menu()
{
	int user_choice;
	
	printf("1.Print Database\r\n");
	printf("2.Add part to database\r\n");
	printf("3.Remove part from database\r\n");
	printf("4.Search Database\r\n");
	printf("5.Exit Database\r\n");
	
	while( scanf("%d%*c",&user_choice) != 1)
	{
		fflush(stdin);
	}
	
	if(user_choice == 1){ print_database(); }
	if(user_choice == 2){ add_parts_to_database();}
	if(user_choice == 3){ remove_parts_from_database();}
	if(user_choice == 4){ search_database();}
	if(user_choice == 5){ exit_program();}
	else
	{
		printf("Please enter a proper value\r\n");
		menu();
	}
	
	return 0;
}

int main()
{
	get_information_from_file();
	menu();
	return 0;
}