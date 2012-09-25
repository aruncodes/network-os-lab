
 #include "stdio.h"
 #include "sys/ipc.h"
 #include "sys/types.h"
 #include "sys/sem.h"
 #include "stdlib.h"
 
 
	union semnum {
 		int val;
 	} arg;
 
 void main() {
 
 	int id,key;
 	
 	struct sembuf lock={0,1,0};
	struct sembuf unlock={0,-1,0};
 	
 	arg.val=0;
 	
 	key = ftok("sem.c",1);
 	
 	id = semget(key,1, IPC_CREAT | 0666);
 	
 	if( id < 0 ) {
 		printf("Could not obtain semaphore..\n");
 		exit(0);
 	}
 	printf("Semaphore id = %d\n",id);
 	
 	if( semctl(id, 0, SETVAL,arg) < 0) {
 		printf("Failed to initialize semaphore.. \n");
 		exit(0);
 	}
 	printf("Initialized.. ");
 	int m = semctl(id, 0 ,GETVAL);
 	printf("Value = %d\n",m);
 	
 	semop(id,&lock,1);
 	printf("Locked.. ");
 	
 	printf("Value = %d\n",semctl(id, 0 ,GETVAL));
	/* 	
 	FILE *file = fopen("sem.c","r+");
 	if( file == NULL)
 		printf("cant open..");
 	char *str;
 	fread(str,1,100,file);
 	printf("%s\n",str);
	*/
	
 	semop(id,&unlock,1);
 	printf("Unlocked.. ");
 	printf("Value = %d\n",semctl(id, 0 ,GETVAL));
 		
 	semctl(id,0, IPC_RMID);
 	
 	
 }
 
 
 
 
