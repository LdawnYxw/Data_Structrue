#include"Queue.h"

void QueueInit(Queue* pst) {

	assert(pst);

	pst->head = pst->back = NULL;
	pst->size = 0;
}

void QueuePush(Queue* pst, QueueDataType x) {

	assert(pst);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL) {
		perror("malloc fail");
		return;
	}

	newnode->val = x;
	newnode->next = NULL;

	if (pst->back == NULL) {
		pst->back = pst->head = newnode;
	}
	else {
		pst->back->next = newnode;
		pst->back = newnode;
	}

	pst->size++;
}

void QueuePop(Queue* pst) {

	assert(pst);
	assert(pst->head);

	QNode* del = pst->head;
	pst->head = pst->head->next;

	free(del);
	del = NULL;

	if (pst->head == NULL) {
		pst->back = NULL;
	}

	pst->size--;
}

QueueDataType QueueFront(Queue* pst) {

	assert(pst);

	assert(pst->head);

	return pst->head->val;
}

QueueDataType QueueBack(Queue* pst) {
	
	assert(pst);

	assert(pst->back);

	return pst->back->val;
}

bool QueueEmpty(Queue* pst) {

	assert(pst);

	return pst->head == NULL;
}

int QueueSize(Queue* pst) {

	assert(pst);

	return pst->size;
}


void QueueDestroy(Queue* pst) {

	assert(pst);

	QNode* cur = pst->head;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pst->head = pst->back = NULL;
	pst->size = 0;
}

