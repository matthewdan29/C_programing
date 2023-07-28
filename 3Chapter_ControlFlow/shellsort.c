#include <stdio.h>

/* shellsort: sort v[0] ... v[n-1] into increasing order */

void shellsort(int v[], int n)
{
	int gap, i, j, temp; 

	for (gap = n/2; gap > 0; gap /= 2) /* controls the gap between compared elements, shrinking it from n\2 by a factor of two each pass*/
		for (i = gap; i <n; i++) /* this loop steps along the elements*/
			for (j=i-gap; j>0 && v[j]>v[j+gap]; j-=gap) /* compares each pair of elements that separated by gap and reverses any that are out of order*/
			{
				temp = v[j]; 
				v[j] = v[j+gap]; 
				v[j+gap] = temp; 
			}
}

