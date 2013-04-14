/*
*	This code creates a pipe and spawns a child process using fork().
*	the child then becomes the 'more' program and waits for 
*	input on STDIN. The parent process sends data down its 
*	end of the pipe, which is received by the child.
*/
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int fd[2],i;
pid_t child;

if( pipe(fd) != 0 )
{
	//pipe() error
}

child = fork();

if( child == -1 )
{
	//fork() error
}

else if (child == 0 )
{
	close( fd[0] );
	
	if( dup2( fd[0], STDIN_FILENO ) != STDIN_FILENO )
	{
		//write() error
	}
	
	execl("/usr/bin/more", (char *) NULL);
}

else
{
	close( fd[0] );
	for(i=0;i<100;++i)
	{
		if( write(fd[1],"hello\n",6) == -1 )
		{
			//write() error
		}
	}
	
	close( fd[1] );
	waitpid(child,NULL,0);
}