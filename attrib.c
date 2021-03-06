/*
 * attrib.c
 * This file is part of 'File attributes and type in Linux'
 *
 * Copyright (C) 2012 - Arun Babu
 *
 * 'File attributes and type in Linux' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'File attributes and type in Linux' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'File attributes and type in Linux'; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	int main(int argc, char * argv[]) {
		struct stat sb;
		int i;
		
		if( argc < 2 ) {
			printf("\n\nUse file name as argument.. \n\n");
			exit(0);
		}
		if(stat(argv[1], &sb) == -1) {
			printf("File not found!!\n\n");
			exit(0);
		}
		
		printf(" File type:");
		
		
		switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:  printf("block device\n");            break;
		case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
		}
		
		printf("\n Owner Permissions : ");
			
		int ownerperm = sb.st_mode & S_IRWXU;		
		if( ownerperm & S_IRUSR ) printf(" read");
		if( ownerperm & S_IWUSR ) printf(" write");
		if( ownerperm & S_IXUSR ) printf(" execute");	
			
		printf("\n");
		
		printf(" Group Permissions : ");
			
		int grpperm = sb.st_mode & S_IRWXG;		
		if( grpperm & S_IRGRP ) printf(" read");
		if( grpperm & S_IWGRP ) printf(" write");
		if( grpperm & S_IXGRP ) printf(" execute");	
			
		printf("\n");
		
		printf(" Others Permissions : ");
			
		int otherperm = sb.st_mode & S_IRWXO;		
		if( otherperm & S_IROTH ) printf(" read");
		if( otherperm & S_IWOTH ) printf(" write");
		if( otherperm & S_IXOTH ) printf(" execute");	
			
		printf("\n\n");
		printf("Last file access:         %s", ctime(&sb.st_atime));
        printf("Last file modification:   %s", ctime(&sb.st_mtime));

	}
