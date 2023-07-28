#include <stdio.h>

/* count digits, white space, others */
/*This program counts the number of occurences of each digit, of white spaces chars, and of all other characters*/

/*This program is suck in a infinte loop meaning that something is wrong with the condiction it's not reaching a end of file "EOF"*/
int main()
{
	int c, i, nwhite, nother;
	int ndigit[10]; 

	nwhite = nother = 0; 
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0']; 
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite; 
		else 
			++nother;
       	
	printf("digits ="); 
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
		printf(", white space = %d, other = %d\n", nwhite, nother);
}
