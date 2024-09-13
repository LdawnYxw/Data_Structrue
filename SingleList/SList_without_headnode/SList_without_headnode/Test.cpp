#include"SList.h"

void test1() {
	SListNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 4);

	SLPrint(plist);

	SLPushPront(&plist, 0);
	SLPushPront(&plist, 2);
	SLPushPront(&plist, 5);

	SLPrint(plist);
}

void test2() {
	SListNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 4);

	SLPrint(plist);

	SLPushPront(&plist, 0);
	SLPushPront(&plist, 2);
	SLPushPront(&plist, 5);

	SLPrint(plist);

	SLInsert(&plist, SLFind(plist, 2), 10);

	SLPrint(plist);
}

void test3() {
	SListNode* plist = NULL;

	SLPushBack(&plist, 1);
	
	SLPopBack(&plist);

	SLPrint(plist);
}

void test4() {
	SListNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 4);

	SLPrint(plist);

	SLPushPront(&plist, 0);
	SLPushPront(&plist, 2);
	SLPushPront(&plist, 5);

	SLPrint(plist);

	SLErase(&plist, SLFind(plist, 0));

	SLPrint(plist);
}

int main() {

	test4();

	return 0;
}