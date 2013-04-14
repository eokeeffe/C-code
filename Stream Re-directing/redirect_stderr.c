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

int manipulate_stderr()
{
	fprintf(stderr, "This will go to the stderr in the terminal.\n");
     
    //Save position of current standard errput
    fpos_t pos;		// create struct variable pos , will be used to save position in the stderr buffer
    fgetpos(stderr, &pos);		// get the buffer place and put it into the struct variable
    int fd = dup(fileno(stderr));	// 
    freopen("stderr.txt", "w", stderr);
     
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

int main ()
{
	manipulate_stderr();
	
	return 0;
}