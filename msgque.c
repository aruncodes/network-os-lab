/*
 * msgque,c
 * This file is part of Message Queue
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * Message Queue is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Message Queue is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Message Queue; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/msg.h"
#include "stdio.h"

#define	MSGSZ	50

struct msg_buf {
	long mtype;
	char mtext[MSGSZ];
	};

int main ()
{
	
	int msgid;	
	
	msgid = msgget(IPC_PRIVATE,0777);
	
	if( fork() == 0) {
	// child process
		struct msg_buf msg;
		
		printf("C: Enter msg :");
		fgets(msg.mtext,MSGSZ,stdin);
		msg.mtype = 1;
		
		msgsnd(msgid,&msg,MSGSZ,0777);
		
		printf("C: Message send to parent..\n");
		
		msgrcv(msgid,&msg,MSGSZ,2,0777);
		
		printf("C: Msg from child : %s \n",msg.mtext);

	}
	else {
		struct msg_buf msg;
		
		msgrcv(msgid,&msg,MSGSZ,1,0777);
		
		printf("P: Msg from child : %s \n",msg.mtext);
		
		printf("P: Enter msg :");
		fgets(msg.mtext,MSGSZ,stdin);
		
		msg.mtype = 2;
		
		msgsnd(msgid,&msg,MSGSZ,0777);
		printf("P: Message send to child..\n");
	}
	
	return 0;
}
