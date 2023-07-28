/* A block in the list is a structure containing pointer to the name, the replacement text, and the next block in the list. A null next-pointer marks the end of the list */

struct nlist{	/* table entry: */
	struct nlist *next;	/* next entry in chain */
	char *name;		/* defined name */
	char *defn;		/* replacement text */

}; 

/* The pointer array */
#define HASHSIZE 101 

static struct nlist *hashtab[HASHSIZE];		/* pointer table */
