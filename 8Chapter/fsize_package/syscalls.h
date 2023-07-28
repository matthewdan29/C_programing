/* Dirent structure contains the inode number and the name.
 * The maximum length of a filename component is NAME_MAX
 * Opendir returns a pointer to a strucure called DIR
 * This is analogous to FILE, which is used by readdir() and closedir()
 * This infomation is collected into this file */

#define NAME_MAX 14	/* longest filename component; */

typedef struct{			/* portable directory entry */
	long ino;		/* inod number */
	char name[NAME_MAX+1];	/*name + '\0' terminator */
}Dirent; 

typedef struct{			/* minimal DIR: no buffering, etc. */
	int fd;			/* file descriptor for the directory */
	Dirent d;		/* the directory entry */
}DIR; 

DIR *opendir(char *dirname); 
Dirent *readdir(DIR *dfd); 
void closedir(DIR *dfd); 

/* The system call stat() takes a filename and returns all of the information in the inode for that file, or -1 if there is an error */

char *name; 
struct stat stbuf; 
int stat(char *, struct stat *); 

int stat(name, &stbuf); 

/* The structure describing the value returned by stat() looks like this */

struct stat	/* inode informatioin returned by stat */
{
	dev_t	st_dev;		/* device of inode */
	ino_t	st_ino;		/* inode number */
	short	st_mode;	/* mode bits */
	short	st_nlink;	/* number of links to file */
	short	st_uid;		/* owners user id */
	short	st_gid;		/* owners group id */
	dev_t	st_rdev;	/* for special files */
	off_t	st_size;	/* file size in characters */
	time_t	st_atime;	/* time last accessed */
	time_t	st_mtime;	/* time last modified */
	time_t	st_ctime;	/* time originally created */
}; 

/* The st_mode entry contains a set of flags describing the file. The fl*/
/* This a few which is needed for this program */

#define	S_IFMT		0160000		/* type of file: */
#define	S_IFDIR		0040000		/* directory */
#define	S_IFCHR		0020000		/* character special */
#define	SIFBLK		0060000		/* block special */
#define	S_IFREG		0010000		/* regular */

/*... there are more cases*/

/* The following routines are for version 7 and system V UNIX systems; they use the directory information in the header <sys/dir.h>, which looks like this: */

#ifndef	DIRSIZ
#define	DIRSIZ 14
#endif
struct direct{ /* directory entry */
	ino_t d_ino;		/* inode number */
	char	d_name[DIRSIZ];	/* long name does not have '\0'*/
}; 

/* Some versions of the system permit much longer names and have a more complicated directory structure. */

