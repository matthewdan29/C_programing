/*example, consider the problem of dtermining wether two arrays 'a' and 'b' have an element in common*/

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (a[i] == b[j])
				goto found; 
	/* didn't find any common element */
	...
	found: 
		/* got one: a[i] == b[j] */
		..

/* code involving a "goto" can always be written without one, thought perhaps at the price of some repeated tests or extra variable. For example, the array search become */


found = 0; 
for (i = 0; i < n && !found; i++)
	for (j = 0; j < m && !found; j++)
		if (a[i] == b[j])
			found = 1; 
if (found)
	/* got one: a[i-1] == b[j-1] */
	...
else 
	/* didn't find any common element */
	...
