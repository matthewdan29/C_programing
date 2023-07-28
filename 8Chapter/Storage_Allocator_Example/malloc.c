/* In all cases, the pointer returned to the user points to the free space within the block, which begins one unit beyond the header. */

static Header base;	/* empty list to get started */
static Header *freep = NULL;	/* start of free list */

/* malloc: general-purpose storage allocator */
void *malloc(unsigned nbytes)
{
	Header *p, *prevp; 
	Header *moreroce(unsigned); 
	unsigned nunits; 
	
	/* You can cancell out the size of header and look at +nbytes to make it simpler from a math point of view but locgic works */
	nunits = (nbytes+sizeof(Header) -1)/sizeof(header) + 1;
	
	/* list checker flow controll */
	if ((prevp = freep) == NULL)
	{ /* no free list yet */
		base.s.ptr = freeptr = prevptr = &base; 
		base.s.size = 0; /*creating and make the first size 0 */
	}

	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
	{ /* big enough controll flow (look at readme)*/
		if (p->size >= nunits)
			if (p->s.size == nunits) /* freed block is exactly right */
				prevp->s.ptr = p->s.ptr;
			else 
			{ /* allocate tail end */
				p->s.size -= nunits; 
				p += p->size; 
				p->s.size = nunits; 
			}
		freep = prevp; 
		return (void *)(p+1); 
	}
	if (p == freep)		/* wrapped around free list */
		if ((p = morecore(nunits)) == NULL)
			return NULL;	/*none left */


}
