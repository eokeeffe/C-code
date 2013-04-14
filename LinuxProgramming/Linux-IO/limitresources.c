/*
	program on how to limit program resources in linux
	Use setrlimit( ), which allows to control data, rss, CPU usage, maximum stack size and more.
	int setrlimit (int resource, const struct rlimit *rlim);
*/

#include <sys/types.h> 
#include <sys/time.h> 
#include <sys/resource.h> 

	struct rlimit r = { 0, 0 };
	if(setrlimit(RLIMIT_NPROC, &r) != 0)
	{
		/* setrlimit( ) error */
	}
	if(fork() == -1)
	{
		perror("fork");
	}
