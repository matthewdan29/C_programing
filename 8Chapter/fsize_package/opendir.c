int fstat(int fd, struct stat *);

/* opendir: open a directory for readdir calls */
DIR *opendir(char *dirname)
{
	int fd; 
	struct stat stbuf; 

	DIR *dp; 

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
	       return NULL; 
	dp->fd = fd; 
	return dp; 	
}

/* opendir() oepns the directory, verifies that the file is a directory, allocates a directory structure, and records the information */

/* Yes, that fuckin if <statment>  with all those fuckin or "||" logic operators does that controll flow then */
