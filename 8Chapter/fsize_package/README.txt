If the mode obtained from stat() indicates that a file is not a directory, then the size is at hand and can be printed directly. if the name is a directory, however, then we have to process that directory one file at a time; it may return contain sub-directories, so the process is recursive. 

The main routine deals with command-line arguments; it hands each argument to the function fsize().

The function fsize() prints the size of the file. if the file is a directory, however, fsize() first calls dirwalk() to handle all the files in it. Note how the flag names "S_IFMT" and "S_IFDIR" are used to decide if the file is a directory. Parenthesization matters, because the precedence of "&" is lower than of "==". 
The function dirwalk() is a general routine that applies a function to each file in a directory. It opens the directory, loops through the files in it, calling the function on each, then closes the directory and returns. fsize() and dirwalk() call eachother recursively

The opendir() opens the directory, verifies that the file is a directory, allocates a directory structure, and records the information.

The readdir() uses read() to read each directory entry. If a direcotry slot is not currently in use, the inode number is zero, and this position is skipped. Otherwise, the inode number and name are placed in a static structure and a pointer to that is returned to the user. Each call overwrites the information from the previous one.  
