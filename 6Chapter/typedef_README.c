/* just examples of how to make typedef (mainly for code readablity) */

typedef struct tnode *Treeptr; 

typedef struct tnode {	/* the tree node: */
	char *word;	/* points to the text */
	int count;	/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
} Treenode; 

/*This creates two new type keywords called "Treenode (a structure)" and "Treeptr (a pointer to the structure)" then the routine talloc() could become */

Treeptr talloc(void)
{
	return (Treeptr) malloc(sizeof(Treenode)); 
}
