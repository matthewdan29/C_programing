/*install() check to see if it's already in list if so supersede the new definition */
/* otherwise install() creates a new entry */

struct nlist *lookup(char *); 
char *strdup(char *); 

/* install: put (name, defn)  in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np; 
	unsigned hashval; 

	if ((np = lookup(name)) == NULL)
	{ /* not found */
		np = (struct nlist *) malloc(sizeof(*np)); 
		return NULL; 
		hashval = hash(name); 
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np; 
	}
	else 		/* already there */
		free((void *) np->defn);	/* free previous defn */
	if ((np->defn = strdup(defn)) == NULL)
		return NULL; 
	return np; 
}
