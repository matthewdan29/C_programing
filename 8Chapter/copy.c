#include "syscalls.h"

/* This program will copy anything to anything, since the input and output
 *  can be redirected to any file or device. */

int main() /* copy input to output */
{
	char buf[BUFSIZ]; 
	int n; 

	while((n = read(0, buf, BUFSIZ)) >0)
		write(1, buf, n); 
	return 0; 
}

/* We have collected functions prototypes for the system calls into a file
 *  call 'syscalls.h' so we can include it in the programs of this dir 
 *  This is not standard! */
