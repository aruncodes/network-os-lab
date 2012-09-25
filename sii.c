#include "stdio.h"
#include "signal.h"
#include "unistd.h"
#include "stdlib.h"


void interrupt() {
	printf("Interrupt (Ctrl+C) signal captured..\n");
	}

void quitsig() {
	printf("Quit (Ctrl+\\) signal captured..\n");
	}
void alarmsig() {
	printf("Alarm signal captured..\n");
	}
void childsig() {
	printf("Child terminated signal captured..\n");
	}
 int main (int argc, char *argv[])
 {
 	int i;
 	/* define signal handlers */
 	
 	signal(SIGINT,interrupt);
 	signal(SIGQUIT,quitsig);
 	signal(SIGALRM,alarmsig);
 	signal(SIGCHLD,childsig);

 	alarm(1); 	
	
	int f = fork();
 	
 	if( f == 0) // child process
 	{
 		printf("Child running..\n");
 		sleep(2);
 		exit(0);
 	}
 	else //parent process
 	{
 		printf("Parent running..\n");
 		
 		for (i = 0; i < 3; i++)
			sleep(3);
  	}
 	return 0;
 }
