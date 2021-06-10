#include <stdlib.h>
#include "list.h"

TListItem *list_create() {
	TListItem* item;

	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL) {
		(*item).data = NULL;
		(*item).next = NULL;
	}

	return item;
}

TListItm *list_append(TListItem *head, void *data) {
	TListItem *item;

	while ((*head).next != NULL) {
		head = (*head).next;
	}

	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL) {
		(*item).data = data;
		(*item).next = NULL;

		(*head).next = item;
	}

	return item;
}

void list_traverse(TListItem *head, TFunc f) {
	head = head->next;
	while (head != NULL) {
		f(head->data);
		head = head->next;
	}
}

void list_free(TListItem **head) {
	TListItem *ptr, *next;

	ptr = *head;

	while (ptr != NULL) {
		next = (*ptr).next;
		if (ptr->data != NULL)
			free(ptr->data);
		free(ptr);
		ptr = next;
	}

	*head = NULL;
}

TListItem *list_search(TListItem *head, int needle) {
	return NULL;
}

void *list_delete(TListItem *head, TListItem *item) {
}

TListItem *list_insert(TListItem *item, void *data) {
	return NULL;
}