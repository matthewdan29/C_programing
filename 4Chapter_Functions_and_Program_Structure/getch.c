#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

int getch(void)	/* get a (possibly pushed-back) character */
{
	return (buf > 0) ? buf[--bufp] : getchar(); /* if true getchar() if not go back one */	
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n"); 
	else 
		buf[bufp++] = c; 
}


