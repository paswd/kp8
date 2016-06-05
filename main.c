#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"

#define LINEARLIST_ERROR	-90000000000000

void linearlist_halfs_reverse(Linearlist *list)
{
	/*Linearlist *tmp = linearlist_create();
	int size = linearlist_length(list);
	for (int i = 0; i < size / 2; i++) {
		linearlist_push(tmp, -1, linearlist_pop(list, 0));
	}
	while (!linearlist_is_empty(tmp)) {
		linearlist_push(list, -1, linearlist_pop(tmp, 0));
	}
	linearlist_destroy(&tmp);*/

	int size = linearlist_length(list);
	for (int i = 0; i < size / 2; i++) {
		linearlist_push(list, -1, linearlist_pop(list, 0));
	}
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
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				scanf("%d", &pos);
				scanf("%lld", &value);
				linearlist_push(linearlist, pos, value);
				break;
			case 'd':
				scanf("%d", &pos);
				tmp = (long long) linearlist_pop(linearlist, pos);
				if (tmp != LINEARLIST_ERROR) printf("%lld\n", tmp);
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
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	linearlist_destroy(&linearlist);

	return 0;
}
