#ifndef __LIST_H__
#define __LIST_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct listNode {
	struct listNode *next;
	void* val;
} listNode;

listNode* list_insert(listNode*, void*);
listNode* list_delete(listNode*, void*);
void list_print(listNode*);


#endif
