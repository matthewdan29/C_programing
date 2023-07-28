#include <stdio.h>

/* rudimentary calculator from dir 4chapter written with scanf */
int main()
{
	double sum, v; 

	sum = 0; 
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum += v); 
	return 0; 
}
