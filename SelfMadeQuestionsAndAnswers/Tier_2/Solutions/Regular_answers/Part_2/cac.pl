#!/usr/bin/perl -w
############################################
#	Perl script to compile programs for me 
#	This will compile any .c program file using 
#   Gcc , the scripts will be made into executable files
#   
#   Future script will be able to compile some other files too
#	
#	Evan O'Keeffe
#	10324289
#	Date:29/06/2011
############################################
#use strict;
#use warnings;

#print "\n\n";
#print "Default compiler is Gcc works with Linux and Windows Mingw \r\n";
#print "Good Day , This is an auto compiler for C programs\r\n";
#print "This will take all .c files in the directory and compile them for you\r\n";
#print "Are you sure you want to continue compiling all .c programs in the directory?\r\n";
#print "1 to continue and 0 to end script\r\n";
#$positive=<STDIN>;
$positive=1;
print"\n\n\n";

if($positive==1)
{
	
	$ext = ".c";
	
	@files = <*$ext>;				#only files of this extension are compiled , may add something to do other files too
									#although will have to make sure C compiler and Perl are on the system
									
	undef($file="");				#clear the array 
	
	use FindBin '$Bin';
	
	#$Error_Log_Name = "Compilation_error_log.txt";
	
	#open STDERR,'>>',"$Error_Log_Name" or die "Cannot open a filehandle for the stderror stream\r\n";	#open the stderror stream and print to file
																									#this will catch any compilation errors and log them in the file
	
	print STDERR "location = ".$Bin."\r\n";
	
	foreach $file(@files) #so for each file , take from the array @files and place individual components into $file
	{  
		$file_no_extension = substr ( $file , 0 , - 2 ) ; 	#remove all but the last 2 symbols , the .c is the only thing remove
		
		system("gcc -o $file_no_extension $file"); #using a system call ,call the compiler and compile all the programs individually
		
	}
	
	#print "All files of extension .c are now compiled in the directory\r\n";
	#print "Error log created , called Compilation_Error_log.txt r\n";
	#print "Thank you for using my script :-)\r\n";
}
else
{
	die "Ending script\r\n";
}