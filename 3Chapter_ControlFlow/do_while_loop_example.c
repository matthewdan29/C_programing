#include <stdio.h>
/* personaly don't want to use this method unless it's gone make more logical control of reading what i was thinking*/
/* itoa: convert n to characters in s*/
void itoa(int n, char s[])
{
	int i, sign; 

	if ((sign = n) <0) /* record sign */
		n = -n; 	/* make n positive*/
	i = 0; 
	do 
	{ /* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next diget */

	}
	while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-'; 
	s[i] = '\0'; 
	reverse(s); 
}
