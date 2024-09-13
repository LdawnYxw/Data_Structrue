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

void SLPushBack(SLNode** head, SLNDataType x) {

	assert(head);//头节点的地址不可能为空

	SLNode* newnode = CreateNode(x);

	if (*head == NULL) {//没有节点
		*head = newnode;
	}
	else {
		//找尾
		SLNode* tail = *head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void SLPushPront(SLNode** head, SLNDataType x) {
	
	assert(head);

	SLNode* newnode = CreateNode(x);

	newnode->next = *head;
	*head = newnode;
}

SLNode* SLFind(SLNode* head, SLNDataType x) {

	while (head) {
		if (head->val == x) {
			return head;
		}
		head = head->next;
	}

	return NULL;
}

void SLInsert(SLNode** head, SLNode* pos, SLNDataType x) {

	assert(head);
	assert(pos);
	assert(*head);

	if (*head == pos) {
		//头插
		SLPushPront(head, x);
	}else{
		SListNode* prev = *head;
		while (prev->next != pos) {
			prev = prev->next;
		}

		SListNode* newnode = CreateNode(x);
		newnode->next =pos;
		prev->next = newnode;
	}

}

void SLPopBack(SLNode** head) {

	assert(head);
	assert(*head);

	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		SLNode* prev = *head;
		while (prev->next->next != NULL) {
			prev = prev->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}

void SLPopFront(SLNode** head) {

	assert(head);
	assert(*head);

	SLNode* tmp = *head;
	*head = (*head)->next;

	free(tmp);
}

void SLErase(SLNode** head, SLNode* pos) {

	assert(head);
	assert(pos);

	if (*head == pos) {
		SLPopFront(head);
	}
	else {
		SLNode* prev = *head;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLInsertAfter(SLNode* pos, SLNDataType x) {

	assert(pos);

	SLNode* newnode = CreateNode(x);
	
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLEraseAfter(SLNode* pos) {

	assert(pos);
	assert(pos->next);

	SLNode* cur = pos->next;
	pos->next = cur->next;

	free(cur);
	cur = NULL;
}

void SLDestroy(SLNode** head) {
	
	assert(head);

	SLNode* cur = *head;
	while (cur) {
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*head = NULL;
}

