/* A file pointer is a pointer to a structure that contains several pieces of information about the file: 
 * 	A pointer to a buffer,
 * 	A counter of the number of charcters left in the buffer, 
 * 	A pointer to the next character position in the buffer, 
 * 	The file descriptor, 
 * 	Flags describing read/write mode, and error status */

/* The data structure that describes a file is contained in <stdio.h>,
 * #include <stdio.h> must be included in any source file that uses routine from the standard input/output library. */

#define NULL	0
#define EOF	(-1)
#define BUFSIZE	1024
#define OPEN_MAX 20	/* MAX #files open at once */

typedef struct _iobuf{
	int cnt;	/* characters left */
	char *ptr;	/* next character position */
	char *base;	/* location of buffer */
	int flag;	/* mode of file access */
	int fd;		/* file descriptor */
} FILE; 

extern FILE _iob[OPEN_MAX]; 

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags 
{
	_READ	=	01,	/* file open for reading */
	_WRITE =	02,	/* file open for writting */
	_UNBUF =	04,	/* file is unbuffered */
	_EOF =		010,	/* EOF has occured on this file */
	_ERR =		020,	/* error occurred on this file */
}; 

int _fillbuf(FILE *); 
int _flushbuf(int, FILE *); 

#define feof(p)		(((p)->flag & _EOF) != 0)
#define ferror(p)	(((p)->flag & _ERR) != 0)
#define fileno(p)	((p)->fd)

#define getc(p)		(--(p)->cnt >= 0 \ ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putc(x,p) 	(--(p)->cnt >= 0 \ ? *(p)->ptr++ = (x) : _flushbuf((x),p))  /* If your really studiung this please take a second and look over the logic here is fucking dope */

#define getchar()	getc(stdin)
#define putcher(x)/* recheck this it might be "putchar(x)" */	putc((x), stdout)

