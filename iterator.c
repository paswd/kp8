#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "iterator.h"
#include "linearlist.h"

#define LINEARLIST_ERROR	-90000000000000

struct _iterator {
	LinearlistElement *value;
};

Iterator *iterator_create()
{
	Iterator *nw = (Iterator *) calloc(1, sizeof(Iterator));
	nw->value = NULL;
	return nw;
}

void iterator_destroy(Iterator **it)
{
	//free((*it)->value);
	free(*it);
	*it = NULL;
}

bool is_iterators_equal(Iterator *lhs, Iterator *rhs)
{
	return lhs->value == rhs->value;
}

void iterator_next(Iterator *it, Linearlist *list)
{
	it->value = linearlist_get_next(list, it->value);
}
LinearlistElement *iterator_fetch(Iterator *it)
{
	return it->value;
}
void iterator_store(Iterator *it, LinearlistElement *el)
{
	it->value = el;
}

void iterator_set_first(Iterator *it)
{
	it->value = NULL;
}
void iterator_set_last(Iterator *it, Linearlist *list)
{
	it->value = linearlist_get_last(list);
}
void iterator_set_position(Iterator *it, Linearlist *list, int pos, bool *err)
{
	it->value = linearlist_get_prev_element_by_position(list, pos, err);
	//it->value = it->value;
}
