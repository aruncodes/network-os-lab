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
