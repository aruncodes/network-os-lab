/**
*
*	First Come First Serve (FCFS)
*	(C) Arun Babu <zyberkiddy@yahoo.com>
*/

#include "stdio.h"

void main() {

	int i,n,cpu_burst[25];
	int wait_time[25],turn_around[25];
	int cur_time=0,tot_wt=0,tot_tat=0;
	
	printf("Enter no. of processes :");
	scanf("%d",&n);
	
	for (i = 0; i < n; i++)
	{			
		printf("\n Process %d :\n",i+1);
		printf("CPU Burst time :");
		scanf("%d",&cpu_burst[i]);
	}
	
	printf("%10s\t%15s\t%15s\t%20s\n",
	"Process ID","Waiting Time","CPU Burst Time","Turn Around Time");
	for (i = 0; i < n; i++)
	{
		wait_time[i] = cur_time;
		//process executes
		cur_time += cpu_burst[i];
		turn_around[i] = cur_time;
		printf("%5d\t\t%7d\t\t%7d\t\t%10d\n",i+1,wait_time[i],cpu_burst[i],turn_around[i]);
		
		tot_wt += wait_time[i];
		tot_tat += turn_around[i];
	}
	printf("Avg. waiting time = %f\n",(float)tot_wt/n);
	printf("Avg. turn around time = %f\n",(float)tot_tat/n);
}

