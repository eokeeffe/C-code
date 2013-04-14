/*
*	Program shows how to run a program in the background in linux enviroment
*	like the shell does
*/

#include<unistd.h>
#include<sys/types.h>

pid_t child;
child = fork();

if( child == -1 )
{
	//fork() error
}
else if( child ==0 )
{
	if( setsid() == -1 )
	{
		//setsid() error
	}
}
else
{
	return (0);
}

/*
	program continues here
*/