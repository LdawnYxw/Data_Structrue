#include"DList.h"

void test1() {
	DLNode* head = DLInit();

	DLPushBack(head, 1);
	DLPushBack(head, 3);
	DLPushBack(head, 1);
	DLPushBack(head, 4);

	DLPushPront(head, 0);
	DLPushPront(head, 2);
	DLPushPront(head, 5);

	DLPrint(head);
}

void test2() {
	DLNode* head = DLInit();

	DLPushBack(head, 1);
	DLPushBack(head, 3);
	DLPushBack(head, 1);
	DLPushBack(head, 4);

	DLPushPront(head, 0);
	DLPushPront(head, 2);
	DLPushPront(head, 5);

	DLPrint(head);
    
	DLInsert(DLFind(head, 2), 3);

	DLPrint(head);
}

void test3() {
	DLNode* head = DLInit();

	DLPushBack(head, 1);
	DLPushBack(head, 3);
	DLPushBack(head, 1);
	DLPushBack(head, 4);

	DLPushPront(head, 0);
	DLPushPront(head, 2);
	DLPushPront(head, 5);

	DLPrint(head);

	DLInsert(DLFind(head, 2), 3);

	DLPrint(head);

	DLErase(DLFind(head, 3));

	DLPopBack(head);
	DLPopFront(head);

	DLPrint(head);
}

int main() {

	test3();

	return 0;
}