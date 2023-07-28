#include <fcnt1.h>

int fd; 
int open(char *name, int flags, int perms); 
fd = open(name, flags, perms); 

/* As with fopen(), the "name" argument is a character strinng containing the file name.
 * The second argument, flags, is an int that specifies how the file is to be opened*/
	/*O_RDONLY = open for reading only
	 * O_WRONGLY = open for writing only
	 * O_RDWR = open for both reading and writing */

/* To open an existing file for reading */
fd = open(name, O_RDONLY,0); 
/* The "perms" argument is always zero for the uses of open. */

/* It is an error to try to open an file that does not exit. 
 * The system call creat() is provided to create new files, or to re-write old ones. */
int creat(char *name, int perms); 
fd = creat(name, perms); 
/* This returns a file descriptor if it was able to create the file, and -1 if not. if the file already exists, creat() will truncate it to zero length, thereby discarding its previous contents; it is not an error to creat() a file that already exits. */
