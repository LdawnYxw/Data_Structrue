#include"SeqList.h"

void test1() {
	SL p;
	SLInit(&p);

	SLPushBack(&p, 1);
	SLPushBack(&p, 3);
	SLPushBack(&p, 1);
	SLPushBack(&p, 4);

	SLPushFront(&p, 0);
	SLPushFront(&p, 2);
	SLPushFront(&p, 5);

	SLPrint(&p);

	SLDestroy(&p);
}

void test2() {
	SL p;
	SLInit(&p);

	SLPushBack(&p, 1);
	SLPushBack(&p, 3);
	SLPushBack(&p, 1);
	SLPushBack(&p, 4);

	SLPushFront(&p, 0);
	SLPushFront(&p, 2);
	SLPushFront(&p, 5);

	SLPrint(&p);

	SLPopBack(&p);
	SLPopBack(&p);

	SLPrint(&p);

	SLPopFront(&p);
	SLPopFront(&p);

	SLPrint(&p);

	SLDestroy(&p);
}

void test3() {
	SL p;
	SLInit(&p);

	SLPushBack(&p, 1);
	SLPushBack(&p, 3);
	SLPushBack(&p, 1);
	SLPushBack(&p, 4);

	SLPushFront(&p, 0);
	SLPushFront(&p, 2);
	SLPushFront(&p, 5);

	SLPrint(&p);

	int pos = SLFind(&p, 2);
	if(pos >= 0) SLErase(&p, pos);
	pos = SLFind(&p, 8);
	if (pos >= 0) SLErase(&p, pos);
	SLPrint(&p);

	SLInsert(&p, 4, 10);
	SLPrint(&p);

	SLInsert(&p, 2, 16);
	SLPrint(&p);

	SLDestroy(&p);
}

int main() {
	test3();
	return 0;
}