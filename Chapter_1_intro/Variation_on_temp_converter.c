/*This is an example of temperature converter for to show there is many ways to change the program but get the same answer like math*/

#include <stdio.h>

/*print Fahrenheit-Celsius table*/

int main()
{
	int fahr;

	/*Notice the for loop fahr is the start of the condition "fahr <= 300" is the condition of the loop. for every iteration of the loop while fahr is lower then 300 it contiues (remember that fahr at the start of the first loop is 0) next "fahr + 20" fahr is just increase by 20 each time think of descrete math*/	
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf( "%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32)); 

}
