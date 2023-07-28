#include <string.h>

/* strlen() returns the length of it's character string argument s, excluding the termenial '\0'*/

/*strlen: retrun length of s */
extern size_t strlen(const char s[]) /* this should be int "strlen(char s[])"*/
{
	int i; 
	
	while (s[i] != '\0')
		++i; 
	return i; 
}
