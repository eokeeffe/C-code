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

int manipulate_stderr() // re-direct the stderr stream , 
{
	fprintf(stderr, "This will go to the stderr in the terminal \r\n");
     
    //Save position of current standard errput
    fpos_t pos;
    fgetpos(stderr, &pos);
    int fd = dup(fileno(stderr));
    freopen("output.txt", "a+", stderr);
     
    fprintf(stderr, "This will go to the file stderr.txt \r\n");
     
    //Flush stderr so any buffered messages are delivered
    fflush(stderr);
    //Close file and restore standard errput to stderr - which should be the terminal
    dup2(fd, fileno(stderr));
    close(fd);
    clearerr(stderr);
    fsetpos(stderr, &pos);
     
    fprintf(stderr, "This will go to the stderr in the terminal \r\n");
}

int manipulate_stdout() // re-direct the stdout stream to the file
{
	fprintf(stdout, "This will go to the stdout in the terminal \r\n");
     
    //Save position of current standard output
    fpos_t pos;
    fgetpos(stdout, &pos);
    int fd = dup(fileno(stdout));
    freopen("output.txt", "a+", stdout);
     
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
	manipulate_stderr();
	
	return 0;
}