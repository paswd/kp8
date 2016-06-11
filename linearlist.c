#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"
#include "names.h"

#define LINEARLIST_ERROR	-90000000000000

struct _linearlist_element {
	Item value;
	LinearlistElement *next;
};

struct _linearlist {
	LinearlistElement *first;
	LinearlistElement *last;
	int size;
};

Linearlist *linearlist_create()
{
	Linearlist *nw = (Linearlist *) calloc(1, sizeof(Linearlist));
	nw->size = 0;
	nw->first = NULL;
	nw->last = NULL;
	return nw;
}

void linearlist_destroy(Linearlist **list)
{
	LinearlistElement *del = (*list)->first;
	while (del != NULL) {
		LinearlistElement *tmp = del->next;
		free(del);
		del = tmp;
	}
	free (*list);
	*list = NULL;
}

void linearlist_push(Linearlist *list, LinearlistElement *element, Item value)
{
	LinearlistElement *nw = (LinearlistElement *) calloc(1, sizeof(LinearlistElement));
	nw->value = value;
	list->size++;
	if (element == NULL) {
		nw->next = list->first;
		list->first = nw;
		if (list->first->next == NULL)
			list->last = list->first;
		return;
	}
	nw->next = element->next;
	element->next = nw;
	if (element == list->last)
		list->last = nw;
}

Item linearlist_pop(Linearlist *list, LinearlistElement *prev)
{
	Item value;
	LinearlistElement *el_del;
	if (prev == NULL) {
		if (list->first == NULL) {
			printf("Linearlist is empty\n");
			return LINEARLIST_ERROR;
		}
		el_del = list->first;
		list->first = list->first->next;
		value = el_del->value;
		free(el_del);
		list->size--;
		return value;
	}
	if (prev->next == NULL) {
		printf("Element is out of range\n");
		return LINEARLIST_ERROR;
	}
	list->size--;
	el_del = prev->next;
	prev->next = prev->next->next;
	value = el_del->value;
	if (list->last == el_del)
		list->last = prev;
	free(el_del);
	return value;
}	

void linearlist_print(Linearlist *list)
{
	LinearlistElement *tmp = list->first;
	while (tmp != NULL) {
		printf("%lld ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int linearlist_length(Linearlist *list)
{
	return list->size;
}

LinearlistElement *linearlist_get_first(Linearlist *list)
{
	return list->first;
}
LinearlistElement *linearlist_get_last(Linearlist *list)
{
	return list->last;
}
LinearlistElement *linearlist_get_prev_element_by_position(Linearlist *list, int pos, bool *err)
{
	*err = false;
	if (pos == -1 || pos == list->size)
		return list->last;
	if (pos > list->size || pos < -1) {
		printf("Element is out of range\n");
		*err = true;
		return NULL;
	}
	if (pos == 0)
		return NULL;
	LinearlistElement *tmp = list->first;
	for (int i = 0; i < pos - 1 && tmp != NULL; i++) {
		tmp = tmp->next;
	}
	return tmp;
}

Item linearlist_get_value(LinearlistElement *element)
{
	return element->value;
}
LinearlistElement *linearlist_get_next(Linearlist *list, LinearlistElement *element)
{
	if (element == NULL)
		return list->first;
	return element->next;
}

bool linearlist_is_empty(Linearlist *list)
{
	if (list->first != NULL)
		return false;
	return true;
}

/*int sz(Linearlist *list)
{
	LinearlistElement *tmp = list->first;
	int cnt = 0;
	while (tmp != NULL) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;
}*/

void linearlist_clear(Linearlist *list)
{
	LinearlistElement *del = list->first;
	while (del != NULL) {
		LinearlistElement *tmp = del->next;
		free(del);
		del = tmp;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}
