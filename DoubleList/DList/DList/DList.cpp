#include"DList.h"

DLNode* CreatDLNode(DLTDataType x) {

	DLNode* newnode = (DLNode*)malloc(sizeof(DLNode));
	if (newnode == NULL) {
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

DLNode* DLInit() {

	DLNode* head = CreatDLNode(-1);
	head->next = head;
	head->prev = head;

	return head;
}

void DLPrint(DLNode* head) {

	assert(head);
	printf("head <=> ");

	DLNode* cur = head->next;
	while (cur != head) {
		printf("%d <=> ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void DLPushBack(DLNode* head, DLTDataType x) {
	
	assert(head);

	DLNode* tail = head->prev;
	DLNode* newnode = CreatDLNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
}

void DLPushPront(DLNode* head, DLTDataType x) {

	assert(head);

	DLNode* tail = head->next;
	DLNode* newnode = CreatDLNode(x);

	head->next = newnode;
	newnode->prev = head;
	newnode->next = tail;
	tail->prev = newnode;
}

DLNode* DLFind(DLNode* head, DLTDataType x) {

	assert(head);

	DLNode* cur = head->next;
	while (cur != head) {
		if (cur->val == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void DLInsert(DLNode* pos, DLTDataType x) {

	assert(pos);

	DLNode* tail = pos->prev;
	DLNode* newnode = CreatDLNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pos;
	pos->prev = newnode;
}

void DLPopBack(DLNode* head) {
	
	assert(head);

	assert(head->next != head);

	DLErase(head->prev);
}

void DLPopFront(DLNode* head) {

	assert(head);

	assert(head->next != head);

	DLErase(head->next);
}

void DLErase(DLNode* pos) {

	assert(pos);

	DLNode* tail = pos->prev;
	
	tail->next = pos->next;
	pos->next->prev = tail;

	free(pos);
}

void DLDestroy(DLNode* head) {

	assert(head);

	DLNode* cur = head->next;
	while (cur != head) {
		DLNode* tail = cur->next;
		free(cur);
		cur = tail;
	}

	free(head);
}