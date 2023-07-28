#include <stdio.h>

/* count characters in input; 2nd version */

int main()
{
	double nc; 
	
	for (nc = 0; getchar() != EOF; ++nc);
       /* "printf" uses "%f" for both float and double; "%.0f" supresses the printing of the decimal point and the fraction part, which is zero.*/	
	printf("%.0f\n", nc); 
}
