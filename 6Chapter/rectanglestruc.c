struct point 
{
	int x; 
	int y;
}; 

/* this syntactically analogous to "int x, y, z;" */
struct {...} x, y, z; 

/* defines a variable "pt" */
struct point pt; 

/* this initialzed to "320" and "200" */
struct maxpt = {320, 200}; 

/* this prints it */
printf("%d, %d", pt.x, pt.y); 

/* this compute the distance from the origin (0,0) to pt */
double dist, sqrt(double); 

dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y); 

/* "rect" structure contains two points structures. if we declare screen */
struct rect 
{
struct point pt1; 
struct point pt2; 
}; 

struct rect screen; 

screen.pt1.x; 

/*refers to the x coordinate of the pt1 member of screen */

