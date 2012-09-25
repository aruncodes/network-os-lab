/*
	 * fifo.c
	 * This file is part of FIFO
	 *
	 * Copyright (C) 2012 - Arun Babu
	 *
	 * FIFO is free software; you can redistribute it and/or modify
	 * it under the terms of the GNU General Public License as published by
	 * the Free Software Foundation; either version 2 of the License, or
	 * (at your option) any later version.
	 *
	 * FIFO is distributed in the hope that it will be useful,
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of
	 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 * GNU General Public License for more details.
	 *
	 * You should have received a copy of the GNU General Public License
	 * along with FIFO; if not, write to the Free Software
	 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
	 * Boston, MA  02110-1301  USA
	 */
	
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <stdio.h>
	
	main() {
		char *fifoname = "./fio";
		
		//int fi = mkfifo(fifoname,0xFF);
		int fi = mknod(fifoname, S_IFIFO|0755, S_IFBLK);
		
		if( fi == 0 )
			printf("FIFO created.\n");
		else
			printf("FIFO creation failed..\n");
		
	}
