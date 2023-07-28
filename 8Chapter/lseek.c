/* The following function reads any number of bytes from any arbitray place in a file
 * It returns the number read, or -1 on error */

#include "syscalls.h"

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
	if (lskeek(fd, pos, 0) >= 0) /* get to pos */
		return read(fd, buf, n); 
	else 
		return -1; 
}

/* The return value from lseek() is a long that gives the new position in the file, or -1 if an error orrucrs. */
