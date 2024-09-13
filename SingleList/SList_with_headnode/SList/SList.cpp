#include"SList.h"

void SLPrint(SLNode* head) {
	while (head) {
		printf("%d -> ", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(SLNDataType x) {

	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL) {
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushBack(SLNode* head, SLNDataType x) {

	SLNode* newnode = CreateNode(x);

	SLNode* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = newnode;
	
}

void SLPushPront(SLNode* head, SLNDataType x) {

	SLNode* newnode = CreateNode(x);

	newnode->next = head->next;
	head->next = newnode;
}

SLNode* SLFind(SLNode* head, SLNDataType x) {

	SLNode* cur = head->next;
	while (cur) {
		if (cur->val == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void SLInsert(SLNode* head, SLNode* pos, SLNDataType x) {

	assert(head);
	assert(pos);

	SLNode* prev = head;
	while (prev->next != pos) {
		prev = prev->next;
	}

	SLNode* newnode = CreateNode(x);
	newnode->next = pos;
	prev->next = newnode;
}

void SLPopBack(SLNode* head) {

	assert(head);
	assert(head->next);

	SLNode* prev = head;
	while (prev->next->next != NULL) {
		prev = prev->next;
	}

	free(prev->next);
	prev->next = NULL;
}

void SLPopFront(SLNode* head) {

	assert(head);
	assert(head->next);

	SLNode* tmp = head->next;
	head->next = head->next->next;

	free(tmp);
	tmp = NULL;
}

void SLErase(SLNode* head, SLNode* pos) {

	assert(head);
	assert(head->next);
	assert(pos);

	SLNode* prev = head;
	while (prev->next != pos) {
		prev = prev->next;
	}

	prev->next = pos->next;

	free(pos);
	pos = NULL;
}

void SLDestroy(SLNode* head) {
	
	assert(head);

	SLNode* cur = head->next;
	while(cur){
		SLNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}

	head->next = NULL;
}



