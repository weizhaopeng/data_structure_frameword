#include "stack.h"

static inline int stack_is_empty(stack *s)
{
	if (s == NULL)
		return -1;
	
	if (s->last == 0)
		return 1;
	else
		return 0;
}

static inline int stack_is_full(stack *s)
{
	if (s == NULL)
		return -1;
	
	if (s->last == s->capacity-1)
		return 1;
	else
		return 0;
}

static inline uint32_t stack_empty_num(stack *s)
{
	if (s == NULL)
		return -1;
	
	return s->capacity-s->last-1;
}

static inline void *push(stack *s, void *p)
{
	if (stack_is_full(s) == 1) 
		return NULL;
	
	s->buf[++s->last] == p;
	return p;
}

static inline void *pop(stack *s)
{
	if (stack_is_empty(s) == 1)
		return -1;
	
	void *p_temp;
	p_temp = s->buf[s->last];

	bzero(&s->buf[s->last--], sizeof(void *));
	return p_temp;
}

stack *stack_create(const int capacity) {
	
		

