#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include <stdbool.h>
#include "names.h"

typedef struct _linearlist_element LinearlistElement;
typedef struct _linearlist Linearlist;

Linearlist *linearlist_create();
void linearlist_destroy(Linearlist **list);

void linearlist_push(Linearlist *list, LinearlistElement *element, Item value);
Item linearlist_pop(Linearlist *list, LinearlistElement *prev);
void linearlist_print(Linearlist *list);
int linearlist_length(Linearlist *list);

LinearlistElement *linearlist_get_first(Linearlist *list);
LinearlistElement *linearlist_get_last(Linearlist *list);
LinearlistElement *linearlist_get_prev_element_by_position(Linearlist *list, int pos, bool *err);
Item linearlist_get_value(LinearlistElement *element);
LinearlistElement *linearlist_get_next(Linearlist *list, LinearlistElement *element);
bool linearlist_is_empty(Linearlist *list);
//int sz(Linearlist *list);
void linearlist_clear(Linearlist *list);

#endif
