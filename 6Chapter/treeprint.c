#include <WordFrequency.h>
#include <stdlib.h>
#include <stdio.h>

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left); 
		printf("%4d %s\n", p->count, p->word); 
		treeprint(p->right); 
	}
}

/* worse case you can get a scewed left or scewed right tree if it's already sorted this is this isn't a 3 node left leaning tree that balances dynamicly. thie could lead to o(n^(2+2)) */
