#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"
#include "iterator.h"
#include "names.h"

#define LINEARLIST_ERROR	-90000000000000

void linearlist_halfs_reverse(Linearlist *list)
{
	Iterator *it_first = iterator_create();
	Iterator *it_last = iterator_create();
	iterator_set_last(it_last, list);
	int size = linearlist_length(list);
	for (int i = 0; i < size / 2; i++) {
		//linearlist_print(list);
		linearlist_push(list, iterator_fetch(it_last), linearlist_pop(list, iterator_fetch(it_first)));
		iterator_set_first(it_last);
		iterator_set_last(it_last, list);
	}
	iterator_destroy(&it_first);
	iterator_destroy(&it_last);
}

int main(void)
{
	Linearlist *linearlist = linearlist_create();
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <position> <value> - push to linearlist\n(set position `-1` if you want to pust to the end of linearlist)\n");
	printf("d <position> - pop from linearlist and print popped item\n");
	printf("r - reverse halfs of linearlist\n");
	printf("p - print linearlist\n");
	printf("l - print linearlist length\n");
	printf("c - clear linearlist\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");
	while (true) {
		char cmd;
		Item value = 0;
		int pos = 0;
		bool is_finished = false;
		scanf("%c", &cmd);
		long long tmp;
		//LinearlistElement *this = NULL;
		bool err = false;
		Iterator *it = iterator_create();
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				scanf("%d", &pos);
				scanf("%lld", &value);
				//this = linearlist_get_prev_element_by_position(linearlist, pos, &err);
				iterator_set_position(it, linearlist, pos, &err);
				/*if (iterator_fetch(it) == this)
					printf("true\n");
				else
					printf("false\n");*/
				/*if (err)
					break;*/
				//linearlist_push(linearlist, this, value);
				linearlist_push(linearlist, iterator_fetch(it), value);
				break;
			case 'd':
				scanf("%d", &pos);
				//this = linearlist_get_prev_element_by_position(linearlist, pos, &err);
				iterator_set_position(it, linearlist, pos, &err);
				if (err)
					break;
				tmp = (long long) linearlist_pop(linearlist, iterator_fetch(it));
				if (tmp != LINEARLIST_ERROR)
					printf("%lld\n", tmp);
				break;
			case 'r':
				linearlist_halfs_reverse(linearlist);
				break;
			case 'p':
				linearlist_print(linearlist);
				break;
			case 'l':
				printf("%d\n", linearlist_length(linearlist));
				//printf("%d\n", sz(linearlist));
				break;
			case 'c':
				//printf("%d\n", linearlist_get_size(linearlist));
				linearlist_clear(linearlist);
				break;
			case '\n':
				break;
			default:
				printf("Invalid command `%c`\n", cmd);
				break;
		}
		iterator_destroy(&it);
		if (is_finished) break;

		//printf("First: %lld\n", (long long) linearlist_get_value(linearlist_get_first(linearlist)));
		//printf("Last: %lld\n", (long long) linearlist_get_value(linearlist_get_last(linearlist)));
	}
	printf("Goodbye!\n");

	linearlist_destroy(&linearlist);

	return 0;
}
