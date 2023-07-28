#include <WordFrequency.h>
#include <stdlib.h>
#include <string.h>

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode)); 
}

/* strdup merely copies the string given by it's argument into a safe place. */
char *strdup(char *s)	/* make a duplicate of s */
{
	char *p; 

	p = (char *) malloc(strlen(s) + 1);	/* +1 for '0' */
	if (p != NULL)
		strcpy(p, s); 
	return p; 
}
