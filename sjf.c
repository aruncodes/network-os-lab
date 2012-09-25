/**
*
*	Shortest Job First
*	(C) Arun Babu <zyberkiddy@yahoo.com>
*/

#include "stdio.h"

void main() {

	int i,j,n;
	
	struct process {
		int id;
		int burst;
		int wait;
		int turn_around;
	} process[25],tmp;

	int cur_time=0,tot_wt=0,tot_tat=0;
	
	printf("Enter no. of processes :");
	scanf("%d",&n);
	
	for (i = 0; i < n; i++)
	{			
		printf("\nProcess %d :\n",i+1);
		printf("CPU Burst time :");
		scanf("%d",&process[i].burst);
		process[i].id=i+1;
	}
	
	//sort
	for( i = 0;i < n; ++i) {
		for( j=1; j < n; ++j ) {		
			if( process[j].burst < process[j-1].burst ) {
				tmp = process[j];
				process[j] = process[j-1];
				process[j-1] = tmp;
			}
		}
	}
	
	printf("%10s\t%15s\t%15s\t%20s\n",
	"Process ID","Waiting Time","CPU Burst Time","Turn Around Time");
	for (i = 0; i < n; i++)
	{
		//process i
		process[i].wait = cur_time;
		//process i executes
		cur_time += process[i].burst;
		process[i].turn_around = cur_time;
		printf("%5d\t\t%7d\t\t%7d\t\t%10d\n",process[i].id,process[i].wait,
					process[i].burst,process[i].turn_around);
		
		//calc total
		tot_wt += process[i].wait;
		tot_tat += process[i].turn_around;
	}
	printf("Avg. waiting time = %f\n",(float)tot_wt/n);
	printf("Avg. turn around time = %f\n",(float)tot_tat/n);
}

// avg WT, avg TAT
