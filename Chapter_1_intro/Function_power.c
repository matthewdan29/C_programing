#include <stdio.h>

int power(int m, int n); 

/*test power function*/

int main()
{
	int i; 
	for (i = 0; i < 10; ++i)
		printf("%2.1d %d %d\n", i, power(2,i), power(-3,i)); 
	return 0; 
}

/*power: raise base to n-th power; n >= 0 */

int power(int base, int n)
{
	int i, p; 

	p = 1;
       /*The for loop starts a 1 and loops until i is equal to n or greater which ever comes first*/	
	for (i = 1; i <=n; ++i)
		/*the processing of p logic*/
		p = p * base; 
	return p; 
}
