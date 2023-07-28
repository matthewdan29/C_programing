/* Input and output uses the read() and write() system calls, which are accessed from C programs through two functions called read() and write(). 
 * For both, the first arucgment is a file descriptor. 
 * The second argument is a character array in your program where the data is to go to or to come from. 
 * The third argument is the numberof bytes to be transferred. */

int n_read = read(int fd, char *buf, int n); 
int n_written = write(int fd, char *buf, int n); 

/* Each call return a count of the number of bytes transferred. read() the number of bits my be less. write() the return value is the number of bytes written;*/
