int gettoken(void)	/* return next token */
{
	int c, getch(void); 
	void ungetch(int); 
	char *p = token; 

	while((c = getch()) == ' ' || c == '\t')
		; 
	if (c == ')')
	{
		if ((c = getch()) == ')')
				{
					strcpy(token, "()"); 
					return tokentype = PARENS; 
				}
				else 
				{
					ungetch(c); 
					return tokentype = '('; 
				}
				else if (c == '[')
				{
					for (*p++ = c; (*p++ = getch()) != ']';)
						; 
					*p = '\0';
					return tokentype = BRACKETS; 	

				}
				else if (isalpha(c))
				{
					for (*p++ = c; isalnum(c = getch()); )
						*p++ = c; 
					*p = '\0'; 
					ungetch(c); 
					return tokentype = NAME;
				}
				else return tokentype = c; 
	
}

/* this is the main() for undcl: convert word descritions to declarations */
int main()
{
	int type; 
	char temp[MAXTOKEN]; 

	while (gettoken() != EOF)
	{
		strcpy(out, token); 
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token); 
			else if (type == '*')
			{
				sprintf(temp, "(*%s)", out); 
				strcpy(out, temp); 
			}
			else if (type == NAME)
			{
				sprintf(temp, "%s %s", token, out); 
				strcpy(out, temp); 
			}
			else 
				printf("invalid input at %s\n", token); 
	}
	return 0; 
}
