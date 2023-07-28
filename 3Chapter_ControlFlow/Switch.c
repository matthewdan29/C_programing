/* first chapter program to count the occurences of each digit, white space, and all other character, using a sequence of "(if.. else) (if... else)" Here is the same program with switch*/

#include <stdio.h>

int main() /* count digits, white space, others*/
{
	int c, i, nwhite, nother, ndigit[10]; 

	nwhite = nother = 0; 
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;
       /* This program reaches here when stays in the non stoping loop it never get a file to reach end of file just like the first (This is just a example to show the switch method in detail)*/	
	while((c = getchar()) != EOF)
	{
		switch (c) 
		{
			case '0': case '1': case '2': case '3': case '4': case '5': case'6': case '7': case '8': 
				ndigit[c-'0']++; 
				break; 
			case ' ': 
			case '\n': 
			case '\t': 
				nwhite++; 
				break; 
			default: 
				nother++; 
				break; 
		}
	}
	printf("digits="); 
	for (i = 0; i < 10; i++)
		printf("%d", ndigit[i]); 
	printf(", white space = %d, other = %d\n", nwhite, nother); 
	return 0; 
}
