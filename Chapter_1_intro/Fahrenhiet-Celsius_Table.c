/*This function prints the following table of Fahrenheit temps and Celsious equivalents*/



#include <stdio.h>

/*print Fahrenheit-Celsius table for fhr = 0, 20, ..., 300 */

int main()
{
int fahr, celsius; 
int lower, upper, step; 

lower = 0; /* lower limit of temperature scale*/
upper = 300; /*upper limit*/
step = 20; /* step size*/

fahr = lower; 
while (fahr <= upper){
	celsius = 5 * (fahr, celsius); 
	printf("%d\t%d\n", fahr, celsius); 
	fahr = fahr + step; 
	}
}
