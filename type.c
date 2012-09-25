
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	
	main(int argc, char * argv[]) {
		struct stat st;
		int i;
		
		if( argc < 2 ) {
			printf("\n\nUse pathnames as arguments.. \n\n");
			exit(0);
		}
		printf("File : Type \n");
		
		for (i = 1; i < argc ; i += 1)
		{
			if( lstat(argv[i],&st) == 0 ) {
			
				switch(st.st_mode & S_IFMT ){
					case S_IFDIR:	printf("%s : directory \n",argv[i]); break;
					case S_IFREG:	printf("%s : regular file \n",argv[i]); break;
					case S_IFBLK:	printf("%s : block device \n",argv[i]); break;
					case S_IFCHR:	printf("%s : character device\n",argv[i]); break;
					case S_IFIFO:	printf("%s : fifo/pipe file \n",argv[i]); break;
					case S_IFLNK:	printf("%s : symbolic link \n",argv[i]); break;
					case S_IFSOCK:	printf("%s : socket file \n",argv[i]); break;
					default:	printf("%s : unknown \n",argv[i]); break;
				}
			}
			else
				printf("%s : file not found.\n",argv[i]);
		}
		
	}
