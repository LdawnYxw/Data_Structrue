#include"SList.h"

void test1() {
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->val = 0;
	plist->next = NULL;

	SLPushBack(plist, 1);
	SLPushBack(plist, 3);
	SLPushBack(plist, 1);
	SLPushBack(plist, 4);

	SLPrint(plist -> next);

	SLPushPront(plist, 0);
	SLPushPront(plist, 2);
	SLPushPront(plist, 5);

	SLPrint(plist->next);
}

void test2() {
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->val = 0;
	plist->next = NULL;

	SLPushBack(plist, 1);
	SLPushBack(plist, 3);
	SLPushBack(plist, 1);
	SLPushBack(plist, 4);

	SLPrint(plist->next);

	SLPushPront(plist, 0);
	SLPushPront(plist, 2);
	SLPushPront(plist, 5);

	SLPrint(plist->next);

	SLInsert(plist, SLFind(plist->next, 5), 520);

	SLPrint(plist->next);
}

void test3() {
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->val = 0;
	plist->next = NULL;

	SLPushBack(plist, 1);

	SLPopBack(plist);

	SLPrint(plist->next);
}

void test4() {
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->val = 0;
	plist->next = NULL;

	SLPushBack(plist, 1);
	SLPushBack(plist, 3);
	SLPushBack(plist, 1);
	SLPushBack(plist, 4);

	SLPrint(plist->next);

	SLPushPront(plist, 0);
	SLPushPront(plist, 2);
	SLPushPront(plist, 5);

	SLPrint(plist->next);

	SLPopFront(plist);
	SLPopFront(plist);
	SLPopFront(plist);

	SLPrint(plist->next);
}

void test5() {
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->val = 0;
	plist->next = NULL;

	SLPushBack(plist, 1);
	SLPushBack(plist, 3);
	SLPushBack(plist, 1);
	SLPushBack(plist, 4);

	SLPrint(plist->next);

	SLPushPront(plist, 0);
	SLPushPront(plist, 2);
	SLPushPront(plist, 5);

	SLPrint(plist->next);

	SLErase(plist, SLFind(plist, 0));

	SLPrint(plist->next);
}


int main() {
	
	test5();

	return 0;
}