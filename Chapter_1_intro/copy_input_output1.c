#include <stdio.h>

/* copy input to output; 1st version */

int main()
{
	int c; 

	c = getchar(); /*getchar() reads the next input character from a text */
	while (c != EOF) /* "!=" means "not equal to" */
	{
		putchar(c); /*putchar(c) prints a character for call*/
		c = getchar();
	}
}
