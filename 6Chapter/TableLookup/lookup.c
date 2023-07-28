/* If lookup() finds the entry already present, it returns a pointer to it; if not, it returns NULL */

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np; 

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; 	/* found */
	return NULL;			/* not found */
}

/* standard idiom for walking along a linked list */
/* for (ptr = head; ptr != NULL; ptr = ptr->next) */
