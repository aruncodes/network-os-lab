/*
 * signal.c
 * This file is part of signal handling
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * signal handling is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * signal handling is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with signal handling; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */



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
