/* Malloc() and Calloc() obtain blocks of memory dynamically */

void *malloc(size_t n); /* returns a pointer to n bytes of unititialized stroage*/

void *calloc(size_t n, size_t size); /* returns a pointer to enought free space for an anrray of n objects of the specified size, NUll if requested cannot be satisfied */

/* The pointer returned by malloc() or calloc() has the proper alignment for the object in question, but it must be cast into the appropriate type, as in */

int *ip; 

ip = (int *) calloc(n, sizeof(int)); 
/* free(p) frees the space pointed to by 'p', where 'p' was originally obtained by a call to malloc or calloc. */

/* it is also an error to use something after it has been freed. A typical but incorrect piece of code is this loop that frees items from a list (look below) */

for (p = head; p != NULL; p = p->next) /* THIS IS WRONG */
	free(p); /* THIS IS WRONG */

/* The right way is to save whatever is needed before freeing: */
	for (p = head; p !=NULL; p =q )
	{
		q = p->next; /* Look at the logic being used you can se that it's asking for the size of the space to be freed to be the size of the struct next that is being pointed to */ 
		free(p); /* now it is free such a space up*/
	}
