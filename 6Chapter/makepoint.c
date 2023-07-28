/* makepoint: make a point from x and y components */
struct point makepoint (int x, int y)
{
	struct point temp; 

	temp.x = x; 
	temp.y = y; 
	return temp; 
}

/* "makepoint" can now be used to initialize any structure dynamically or to provide structure arguments to a function */

struct rect screen; 
struct point middle; 
struct point makepoint(int, int); 

screen.pt1 = makepoint(0,0); 
screen.pt2 = makepoint(XMAX, YMAX); 
middle = makepoint((screen.pt1.x + screen.pt2.x) /2, (screen.pt1.y + screen.pt2.y) /2); 

/* the next step is a set of functions to do arithmetic on points*/
/* addpoints: add two points */
struct addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x; 
	p1.y += p2.y; 
	return p1; 
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* The following function returns a rectangle guaranteed to be in cononical form*/

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/* cononrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
	struct rect temp; 

	temp.pt1.x = min(r.pt1.x, r.pt2.x); 
	temp.pt1.y = min(r.pt1.y, r.pt2.y); 
	temp.pt2.x = max(r.pt1.x, r.pt2.x); 
	temp.pt2.y = max(r.pt1.y, r.pt2.y); 
	return temp; 
}

/* pointer to a struct */
struct point *pp; 

/* to use "pp" write, */
struct point origin, *pp; 
pp = &origin; 
printf("origin is (%d, %d)\n", (*pp).x, (*pp).y); 
/* you can also use */
pp->x, pp->y; 
