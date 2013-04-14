/*
	Tier 2 : Part 6	:	Question 9
*/
#include<stdio.h>
#include<math.h>

//previous example
#define PRINT(x) printf("%s",x);
#define PRINT_MERSENNE_PRIME(string,prime,newline) printf("%s %d %s",string,prime,newline);

// the same thing occurs here , the start_block and end_block are replaced 
// at compile time with the the curly braces
#define start_block {
#define end_block }
//replace the return 0; , its returning control to the function that called it
#define return_control return 0;
//cannot go beyond this number as it's the total memory size of a signed int
#define signed_int_limit 2147483647 

//this part is a bit more advanced , using the \ character
//you can create multi-line macros 
//this one is the entire main all in the one macro called "the_main_loop"

#define the_main_loop 								  \
			int loop_count = 0,control_statement = 50;\
			while ( loop_count < control_statement )  \
			start_block								  \
			get_mersenne_prime ( loop_count );		  \
			loop_count++;							  \
			end_block								  \
			return_control	
			
#define get_mersenne_prime_number 								\
			int mersenne_prime ;								\
			mersenne_prime = ( (pow(2,get_prime(count)))-1) ;
			
#define check_mersenne_limits 				\
			if ( mersenne_prime < signed_int_limit && mersenne_prime > 1) 

int get_prime();
int get_mersenne_prime(int count);

int main()

start_block
	//The entire function here is now a macro , although it does look neat 
	// this can be horrifically mis-used as when a problem arises 
	// the code has to searched for in the macro
	the_main_loop
	
end_block

// The mersenne function , see how the code would look to someone who isn't a programmer
int get_mersenne_prime(int count)

start_block 
	
	get_mersenne_prime_number
	
	check_mersenne_limits
	
	start_block 
	
		PRINT_MERSENNE_PRIME("Mersenne Prime = ", mersenne_prime ,"\r\n")
	
	end_block
	
	else
		return_control

end_block

// I left the majority of this code unchanged as I didn't want to confuss the feck out of you
int get_prime(int number_to_check_for_primality)
{
	int loop_counter;

	if (number_to_check_for_primality < 2) 
	{
		return number_to_check_for_primality;
	}

	for (loop_counter = 2; loop_counter < number_to_check_for_primality; loop_counter++)
	{
		if ((number_to_check_for_primality % loop_counter) == 0) 
		{
			return_control;
		}
		
	}	

	return number_to_check_for_primality;

}