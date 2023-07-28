#include <stdio.h>
#include <stdlib.h>

/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
	double atof(char s[]); 

	return (int) atof(s); /* this force cast type this is a little unsafe*/
}
