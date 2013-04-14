/*
	Tier 3 : Part 4	:	Question 7
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<assert.h>

int manipulate_stdout()
{
	fprintf(stdout, "This will go to the stdout in the terminal.\n");
     
    //Save position of current standard output
    fpos_t pos;
    fgetpos(stdout, &pos);
    int fd = dup(fileno(stdout));
    freopen("stdout.txt", "w", stdout);
     
    fprintf(stdout, "This will go to the file stdout.txt \r\n");
     
    //Flush stdout so any buffered messages are delivered
    fflush(stdout);
    //Close file and restore standard output to stdout - which should be the terminal
    dup2(fd, fileno(stdout));
    close(fd);
    clearerr(stdout);
    fsetpos(stdout, &pos);
     
    fprintf(stdout, "This will go to the stdout in the terminal \r\n");
}

int main ()
{
	manipulate_stdout();
	
	return 0;
}