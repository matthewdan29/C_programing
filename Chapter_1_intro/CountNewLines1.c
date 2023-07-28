#include <stdio.h>

/*count lines in input */

int main()
{
	int c, nl; 

	nl = 0; 
	while ((c = getchar()) != EOF)
		if (c == '\n') /* this checks only for the end of line char */
			++nl; /* this adds to the nl (new line holder)*/
	printf("%d\n", nl); 
}
