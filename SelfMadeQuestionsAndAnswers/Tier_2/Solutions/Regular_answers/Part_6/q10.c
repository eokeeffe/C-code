/*
	Tier 2 : Part 6	:	Question 10
*/
#include<stdio.h>
#include<math.h>
#include "my_macro.h"

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

int get_prime(int number_to_check_for_primality)
{
	get_a_prime_number_and_return_it
}