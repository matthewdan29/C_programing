/* the only declaration needed for a file pointer is exemplified by */

FILE *fp; 
FILE *fopen(char *name, char *mode); 

/* This says that fp is a pointer to a "FILE", and "fopen" returns a pointer to a "FILE".  */

/* the call to "fopen" in a program is */
fp = fopen(name, mode); 
/* The argument of "fopen" is a character string containing the name of the file.*/
/* The second argument is the mode, also a character string, which indicates how one intends to use the file */
/* Alloable modes include read ("r"), write ("w"), and append ("a"). */
/* some systems distinguish between text and binary files; for the latter "b" */

/* getc() returns the next character from a file */
int getc(FILE *fp); 


/* putc() is an output function */
int putc(int c, FILE *fp); 
/* putc() writes the character c to the file fp and returns the character written */

/* getchar() and putchar() can be defined in terms of getc, putc, and stdin, and stdout as follows */
#define getchar()	getc(stdin)
#define putchar(c)	putc((c), stdout)

/* scanf() and printf() for FILES */
int fscanf(FILE *fp, char *format, ... ); 
int fprintf(FILE *fp, char *format, ...); 
