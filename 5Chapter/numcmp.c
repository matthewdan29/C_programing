#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2; 

	v1 = atof(s1); 
	v2 = atof(s2); 
	if (v1 < v2)
		return -1; 
	else if (v1 > v2)
		return 1; 
	else 
		return 0; 
}

/* swap function, exchanges two pointer, is just like the one earlier in the chapter, except that the declarations are changed to "void *" */

void swap(void *v[], int i, int j)
{
	void *temp; 

	temp = v[i]; 
	v[i] = v[j]; 
	v[j] = temp; 
}


