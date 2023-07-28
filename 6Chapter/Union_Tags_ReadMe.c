/* union() a single variable that can legitimately hold any of one of several types the syntax is based on structures: */

union u_tage {
	int ival; 
	float fval; 
	char *sval; 
} u;

/* to access */
u.member or u->member 

/* in the structure array defined by */
struct {
	char *name; 
	int flags; 
	int utype; 
	union {
		int ival; 
		float fval; 
		char *sval; 
	} u; 
} symtab[NSYM]; 

/* member "ival" is referred as */
symtab[i].u.ival

/* and the first character of the string "sval" by either of */
*symtab[i].u.sval; 
symtab[i].u.sval[0]; 
