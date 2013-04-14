/*
*	How do I read and modify the contents of another program's 
*	address space and how do I get process information, like /usr/bin/top?
*
*	There is no portable solution. However, 
*	the ptrace() function is available on BSD, Linux, SunOS, Solaris, 
*	HP-UX (marked deprecated in the man page) - The interface differs slightly, 
*	though. To obtain virtual addresses, use nlist() on the executable file or the KVM library (-lkvm), 
*	if you have it (available on BSD and Sun systems).
*
*	The kinfo_proc structure offers a load of other information, 
*	like amount of pages in text/data/stack segments, owner user/group ID, 
*	tty, resource usage and much more.
*
*	Have a look at /usr/include/sys/user.h, /usr/include/sys/proc.h, 
*	/usr/include/sys/resourcevar.h. Note that this is only the surface of the KVM library. 
*	Consult your manual help pages for further information.
*/

#include <kvm.h> 
#include <sys/types.h> 
#include <sys/ptrace.h> 
#include <unistd.h> 
#include <signal.h> 
#include <stdio.h> 

	pid_t child;
	kvm_t             *kvm;
	struct kinfo_proc *kproc;
	child = fork();
	
	if(child == -1)
	{
		/* fork( ) error */
	}
	else if (child == 0)
	{
		execl("/some/program", (char *) NULL);
	}
		kvm = kvm_open(NULL, "/dev/mem", NULL, O_RDONLY, NULL);
	if(kvm == NULL)
	{
		/* kvm_open( ) error */
	}
		kproc = kvm_getprocs(kvm, KERN_PROC_PID, child, &rc);
	if(kproc == NULL)
	{
		/* kvm_getprocs( ) error */
	}

	if (rc)
	{
		char  *p = kproc->kp_eproc.e_vm.vm_daddr;
		
		int   data;
		
		if (ptrace(PT_ATTACH, child, 0, 0) != 0)
		{
			/* ptrace( ) error */
		}
		
		kill(child, SIGSTOP);
		
		wait(NULL);
		
		errno = 0;
		
		data = ptrace(PT_READ_D, child, p, 0);
		
		if (data == -1 && errno != 0)
		{
			/* ptrace( ) error */
		}
		
		printf("Data segment start: %p\n", p);
		printf("First %d bytes: %x\n", sizeof(data), data);
	}