	#include <sys/types.h>
	#include <sys/wait.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>

	main()	{
		int forkid,status;
		
		forkid = fork();
		
		if( forkid == 0 ) {
			printf(" Inside child process \n");
			printf(" Child PID : %d\n", getpid());
			printf(" Parent PID : %d", getppid());
			
			printf("\n Child is sleeping for 3 seconds.. \n");
			sleep(3);
			printf(" Completed\n Child exiting..\n\n");
			exit(0);
		}
		else {
			printf("\n Parent is waiting for child to exit\n\n");
			wait(&status);
			printf("\n Parent is executing..\n");
			printf(" Parent PID : %d\n", getpid());
		}
	}
