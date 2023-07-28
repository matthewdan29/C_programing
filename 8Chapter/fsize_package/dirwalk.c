#define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH]; 
	Dirent *dp; 
	DIR *dfd; 

	if ((dfd = opendir(dir)) == NULL)
	{/* Checking to see if directory can be opened */
		fprintf(stderr, "dirwalk: can't open %s\n", dir); 
		return; 
	}
	while ((dp = readdir(dfd)) != NULL)
	{
		if (strcmp(dp->name, "..") == 0 || strcmp(dp->name, ".."))
			continue; /* skip self and parent */
		if (strlen(dir)+strlen(dp->name)=2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name); /* error check to see if it's too big for buffer or program */
		else 
		{
			sprintf(name, "%s/%s", dir, dp->name); 
			(*fcn)(name); 
		}
	}	
	closedir(dfd); 
}
