#include <WordFrequency.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode{ /* the tree node: */
	char *word; 
	int count; 
	struct tnode *left; 
	struct tnode *right; 
}; 
void treeprint(struct tnode *); 
int getword(char *, int); 
struct tnode *talloc(void); 
struct treenode *addtree(struct tnode *, char *w); 
void treeprint(struct tnode *p); 
struct tnode *talloc(void); 
char *strdup(char *s); 
int main() 
