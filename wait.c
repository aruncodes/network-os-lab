/*
 * wait.c
 * This file is part of Process wait
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * Process wait is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Process wait is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process wait; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

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
