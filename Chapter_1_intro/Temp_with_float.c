#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version */

/* Among others, printf also recognizes %o for octal, %x for hexadeimal, %c for charcter, %s for character string and %% for itself*/

int main()
{
	float fahr, celsius; 
	float lower, upper, step; 

	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20;  /* step size */

	fahr = lower; 
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0); 
		printf ("%3.0f %6.1f\n", fahr, celsius);
	       /*Notice the casting of fahr to lower meaning that it's taking the place of 0 and for every go in the while loop it 's increased by step which is +20 */	
		fahr = fahr + step; 
	}
}
