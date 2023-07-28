/* Most of fopen() is concerned with getting the file opened and positioned at the right place, and setting the flag bits to indicate the proper state. */

#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666	/* RW for owner, group, others */

FILE *fopen(char *name, char *mode)
{
	int fd; FILE *fp; 

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;		/* found free slot */
	if (fp >= _iob + OPEN_MAX)	/* no fee slots */
		return NULL; 
	if (*mode == 'w')
		fd = creat(name, PERMS); 
	else if (*mode == 'a')
	{
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS); 
		lseek(fd, 0L, 2); 
	}
	else 
		fd = open(name, O_RDONLY, 0); 
	if (fd == -1)		/* couldn't access name */
		return NULL; 
	fp->fd = fd; 
	fp->cnt = 0; 
	fp->base = NULL; 
	fp->flag = (*mode == 'r') ? _READ : _WRITE; 
	return fp; 
}

/* This version of fopen does not handle all the access modes of the standard. 
 * This fopen() does not recongnize the "b" that signals binary access,*/

/* Subsecquent calss to _fillbuf will find a bufer allocated "look at _fillbuff.c"*/
