#include <stdio.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

/* count lines, words, and characters in input */

int main()
{
	int c, nl, nw, nc, state; /*casting to int*/
	
	state = OUT; 
	nl = nw = nc = 0; 
	while ((c = getchar()) != EOF)
	{
		++nc; 
		if (c == '\n')
			++nl; 
		if (c == ' ' || '\n' || c == '\t')
			state = OUT; 
		else if (state == OUT)
		{
			state = IN; 
		}
	}
	printf("%d %d %d\n", nl, nw, nc); 
}

/* Every time the program encounters the first character of a word, it counts one more word, The variable state records whether the program is currently in a word or not; initially it is "not in a word", which is assigned the value OUT.*/


