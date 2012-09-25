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
