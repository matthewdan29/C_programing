/* this program is a protype of grep GNU program that take command line*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max); 

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE]; 
	int found = 0; 

	if (argc != 2)
		printf("Usage: find pattern\n"); 
	else 
		while (getline(line, MAXLINE) >0)
			/* strstr(s,t) returns a pointer to the first occurrence of the string "t" in the string "s", or "NULL" if there is none. */
			if (strstr(line, argv[1]) !=NULL)
			{
				printf("%s", line); 
				found++; 
			}
	return found; 
}
