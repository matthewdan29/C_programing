#include <stdio.h>

/* count characters in input; 1st version */

int main()
{
	long nc; 

	nc = 0; 
	while (getchar() != EOF)
		++nc; /*new operator ++, which means increment by one. you can use nc = nc + 1 but ++nc is more concise and often more efficient.*/
	printf("%ld\n", nc); 
}
