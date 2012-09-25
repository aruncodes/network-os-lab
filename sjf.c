/**
*
*	Shortest Job First
*	(C) Arun Babu <zyberkiddy@yahoo.com>
*/
/*
 * sjf.c
 * This file is part of 'Shortest Job First'
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * 'Shortest Job First' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'Shortest Job First' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'Shortest Job First'; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
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
