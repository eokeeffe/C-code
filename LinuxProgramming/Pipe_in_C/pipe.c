#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


void error(char *s);
char *data = "Some input data\n";

main()
{
	int in[2], out[2], n, pid;
	char buf[255];

	/* In a pipe, xx[0] is for reading, xx[1] is for writing */
	if (pipe(in) < 0)
	{
		error("pipe in");
	}
	if (pipe(out) < 0)
	{
		error("pipe out");
	}

	if (( pid = fork() ) == 0) 
	{
		/* This is the child process */

		/* Close stdin, stdout, stderr */
		close(0);
		close(1);
		close(2);
		/* make our pipes, our new stdin,stdout and stderr */
		dup2(in[0],0);
		dup2(out[1],1);
		dup2(out[1],2);

		/* Close the other ends of the pipes that the parent will use, because if
		* we leave these open in the child, the child/parent will not get an EOF
		* when the parent/child closes their end of the pipe.
		*/
		close(in[1]);
		close(out[0]);

		/* Over-write the child process with the hexdump binary */
		execl("/usr/bin/hexdump", "hexdump", "-C", (char *)NULL);
		error("Could not exec hexdump");
	}

	printf("Spawned 'hexdump -C' as a child process at pid %d\n", pid);

	/* This is the parent process */
	/* Close the pipe ends that the child uses to read from / write to so
	* the when we close the others, an EOF will be transmitted properly.
	*/
	close(in[0]);
	close(out[1]);

	printf("<- %s", data);
	/* Write some data to the childs input */
	write(in[1], data, strlen(data));

	/* Because of the small amount of data, the child may block unless we
	* close it's input stream. This sends an EOF to the child on it's
	* stdin.
	*/
	close(in[1]);

	/* Read back any output */
	n = read(out[0], buf, 250);
	buf[n] = 0;
	printf("-> %s",buf);
	exit(0);
}

void error(char *s)
{
	perror(s);
	exit(1);
}
