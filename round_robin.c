/**
*
*	Round Robin
*	(C) Arun Babu <zyberkiddy@yahoo.com>
*/
/*
 * round_robin.c
 * This file is part of 'Round Robin Sched Algm'
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * 'Round Robin Sched Algm' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'Round Robin Sched Algm' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'Round Robin Sched Algm'; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

#include "stdio.h"

void main() {

	int i,j,n,quant,finished=0;
	
	struct process {
		int id;
		int burst;
		int wait;
		int turn_around;
		int remaining;
	} process[25],tmp;

	int cur_time=0,tot_wt=0,tot_tat=0,cur_burst=0;
	
	printf("Enter no. of processes :");
	scanf("%d",&n);
	
	printf("Enter time quantum : ");
	scanf("%d",&quant);
	
	for (i = 0; i < n; i++)
	{			
		printf("\nProcess %d :\n",i+1);
		printf("CPU Burst time :");
		scanf("%d",&process[i].burst);
		process[i].remaining = process[i].burst;
		process[i].id=i+1;
	}
	
	printf("%10s\t%15s\t%15s\t%20s\t%20s\n",
	"Process ID","Waiting Time","CPU Burst Time","Remaining Time","Turn Around Time");
	
	j = i= 0;
	while(1)
	{
		if( process[i].remaining > 0) {
			//process i
			process[i].wait = cur_time - (process[i].burst - process[i].remaining);

			if( process[i].remaining < quant )
				cur_burst = process[i].remaining;
			else
				cur_burst = quant;
				
			//process i executes
			cur_time += cur_burst;
			process[i].remaining -= cur_burst;
			process[i].turn_around = cur_time;
			printf("%5d\t\t%7d\t\t%7d\t\t%10d\t\t%10d\n",process[i].id,process[i].wait,
						cur_burst,process[i].remaining,process[i].turn_around);

			if(process[i].remaining == 0)
				finished++;
		}
		
		if( finished == n) break;
		
		j++;
		i = j%n;
	}
	for (i = 0; i < n; i++)	{
		//calc total
		tot_wt += process[i].wait;
		tot_tat += process[i].turn_around;
		printf("Turn around time of process %d = %d\n",process[i].id,process[i].turn_around );
	}
	printf("Avg. waiting time = %f\n",(float)tot_wt/n);
	printf("Avg. turn around time = %f\n",(float)tot_tat/n);
}

// avg WT, avg TAT
