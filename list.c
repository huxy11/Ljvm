#include "list.h"


listNode* list_insert(listNode* head, void* val) {
	listNode **cur = &head;
	while(*cur) 
		cur = &((*cur)->next);
	(*cur) = malloc(sizeof(listNode));
	printf("head = %p\n", head);
	return head;
}

listNode* list_delete(listNode* head, void* val) {
	listNode **cur = &head;
	while(*cur) {
		if ((*cur)->val == val) {
			listNode* tmp = *cur;
			*cur = tmp->next;
			free(tmp->val);
			free(tmp);
			*cur = NULL;
			return head;
		} else 
			cur = &((*cur)->next);
	}
	return head;
}

void list_print(listNode* head) {
	listNode **cur = &head;
	for (int i =0; *cur; ++i)
		printf("%d: %d @ %p\n", i, *((int*)((*cur)->val)), (*cur)->val);
}
