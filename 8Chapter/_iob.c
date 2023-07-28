/* The only remaining loose end is how everything gets started.
 *  The array "_iob" must be defined and initialized for "stdin, stdout & stderr" */

FILE _iob[OPEN_MAX] = { /* stdin, stdout, and stderr */
	{0, (char *) 0, (char *) 0, _READ, 0}, 
	{0, (char *) 0, (char *) 0, _WRITE, 1},
	{0, (char *) 0, (char *) 0, _WRITE, | _UNBUF, 2}
};

/* The initialization of the "flag" part of the structure shows that "stdin" is to be read, "stdout" is to be written, "stderr" is to be written unbuffered. */
