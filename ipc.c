	
	#include "stdlib.h"
	#include "unistd.h"
	#include "string.h"
	#include "stdio.h"
	
	#define MSG_SIZE	17
	
	int 
	main ()
	{
		
		int child_pipe[2],parent_pipe[2];
		
		//create pipes
		pipe(child_pipe);
		pipe(parent_pipe);
		
		if( fork() == 0 ) { //child process
			
			printf("C: sending message to parent. \n");
			
			char msg[20] = "My name is child..";
			
			write(child_pipe[1],msg,MSG_SIZE);
			
			printf("C: Waiting for 2 seconds for parent message.\n");
			sleep(2);
			
			read(parent_pipe[0],msg,MSG_SIZE);
			printf("C: Message from parent : %s \n",msg);
		}
		else { //parent process
			printf("P: Waiting 1 second for message from child. \n");
			sleep(1);
			
			char msg[20];
			
			read(child_pipe[0],msg,MSG_SIZE);
			msg[MSG_SIZE]='\0';
			printf("P: Message from child : %s\n",msg);
			
			printf("P: Sending message to child. \n");
			char msg2[20] = "My name is parent.";
			
			write(parent_pipe[1],msg2,MSG_SIZE);
			
			sleep(1);
		}
		
		return 0;
	}
