#include <stdio.h>

struct nlist *install(char *name, char *defn); 
struct nlist *lookup(char *); 
char *strdup(char *); 
unsigned hash(char *s); 
struct nlist{ /* table entry: */
	struct nlist *next;	/* next entry in chain */
	char *name;		/* defined name */
	char *defn;		/* replacement text */
}; 

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];		/* pointer table */
