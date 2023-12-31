#include <WordFrequency.h>
#include <stddef.h>
#include <string.h>
/* addtree() is recursive. */

struct tnode *talloc(void); 

char *strdup(char *); 

/* addtree: add a node with w, at or below p */
struct treenode *addtree(struct tnode *p, char *w)
{
	int cond; 

	if (p == NULL) /* a new word has arrived */
	{
		p = talloc();	/* make a new node */
		p->word = strdup();	/* look at the p accessing word in struc*/
		p->count = 1; 
		p->left = p->right = NULL; 
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;	/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w); 
	else			/* greater that into right subtree */
		p->right = addtree(p->right, w); 
	return p; 
}
