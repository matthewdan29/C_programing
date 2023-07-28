#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	/* max #lines to e sorted */

char *lineptr[MAXLINES];	/* pointers to text lines */
 int getlines(char s[], int lim); 
int readlines(char *lineptr[], int nlines); 
/* void strcpy(char *s, char *t); */
void writelines(char *lineptr[], int nlines);
void afree(char *p);	/* free storage pointed to by p*/
void qsort(char *v[], int left, int right);
/* void swap(char *v[], int i, int j);*/
void copy(char to[], char from[]); 
 
/* sort input lines */
int main()
{
	int nlines;	/* number of input lines read */

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines-1); 
		writelines(lineptr, nlines); 
		return 0;
	}
}	

#define MAXLEN 1000 	/* max length of any input line */
int getline(char s[],int lim)
{
	int c, i; 
	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c; 
	if (c == '\n')
	{
		s[i] = c; 
		++i; 
	}
	s[i] = '\0'; 
	return i; 
}

/* copy: copy 'from' into 'to'; assume to is big enough*/
void copy(char to[], char from[])
{
	int i; 

	i = 0; 
	while ((to[i] = from[i]) != '\0')
		++i;
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];	/* size available space */
static char *allocp = allocbuf;		/* next free positioin */

char *alloc(int n)	/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{/* it fits */
		allocp += n; 
		return allocp - n;	/* old p */
	}
	else /*not enough room */
		return 0; 
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p; 
}

/* strcpy: copy t to s; pointer version 3*/
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines; 
	char *p, line[MAXLEN]; 

	nlines = 0; 
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p = alloc(len) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0';	/* delete newline */
			strcpy(p, line); 
			lineptr[nlines++] = p; 
		}
	return  nlines; 
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
	       printf("%s", *lineptr++); 	
}

/* strlen: return length of string s */
int strlen(char *s)
{
	char *p = s; 
	
	while (*p != '\0')
		p++; 
	return p - s; 	
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
	int i; 

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0; 
	return s[i] - t[i]; 
}

/* qsort: sort v[left].. v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last; 
	void swap(char *v[], int i, int j); 

	if (left >= right)	/* do nothing if array contains */
		return; 	/* fewer than two elements */
	swap(v, left, (left + right)/2); 
	last = left; 
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) <0)
			swap(char *v, ++last, i); 
	swap(v, left, last); 
	qsort(v, left, last-1); 
	qsort(v, last+1, right); 
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp; 

	temp = v[i]; 
	v[i] = v[j]; 
	v[j] = temp;  
}
