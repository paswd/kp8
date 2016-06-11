#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <stdbool.h>
#include "names.h"
#include "linearlist.h"

typedef struct _iterator Iterator;

Iterator *iterator_create();
void iterator_destroy(Iterator **it);

bool is_iterators_equal(Iterator *lhs, Iterator *rhs);
void iterator_next(Iterator *it, Linearlist *list);
LinearlistElement *iterator_fetch(Iterator *it);
void iterator_store(Iterator *it, LinearlistElement *el);
void iterator_set_first(Iterator *it);
void iterator_set_last(Iterator *it, Linearlist *list);
void iterator_set_position(Iterator *it, Linearlist *list, int pos, bool *err);

#endif
