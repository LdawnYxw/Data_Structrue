#include"SeqList.h"

void SLInit(SL* psl) {
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLDestroy(SL* psl) {
	assert(psl);

	if (psl->a != NULL) {
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void SLPrint(SL* psl) {
	assert(psl);

	for (int i = 0; i < psl->size; i++) {
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl) {
	assert(psl);

	if (psl->size == psl->capacity) {//有效数据等于空间容量时需要扩容
		size_t NewCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//二倍扩容

		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * NewCapacity);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}

		psl->a = tmp;
		psl->capacity = NewCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x) {
	assert(psl);

	SLCheckCapacity(psl);

	psl->a[psl->size ++] = x;
}

void SLPushFront(SL* psl, SLDataType x) {
	assert(psl);

	SLCheckCapacity(psl);

	 ++ psl->size;
	 for (size_t i = psl->size - 1; i > 0; i--) {
		 psl->a[i] = psl->a[i - 1];
	 }

	 psl->a[0] = x;
}

void SLPopBack(SL* psl) {
	assert(psl);
	assert(psl->size > 0);

	psl->size--;
}

void SLPopFront(SL* psl) {
	assert(psl);
	assert(psl->size > 0);

	for (int i = 0; i < psl->size - 1; i++) {
		psl->a[i] = psl->a[i + 1];
	}

	psl->size--;
}

int SLFind(SL* psl, SLDataType x) {
	assert(psl);

	for (int i = 0; i < psl->size; i++) {
		if (psl->a[i] == x) {
			return i;
		}
	}

	return -1;
}

void SLInsert(SL* psl, int pos, SLDataType x) {
	assert(psl);
	assert(pos >= 0&& pos < psl->size);

	SLCheckCapacity(psl);

	psl->size++;
	for (size_t i = psl->size - 1; i > pos;i --) {
		psl->a[i] = psl->a[i - 1];
	}

	psl->a[pos] = x;
}

void SLErase(SL* psl, int pos) {
	assert(psl);
	assert(pos >= 0 && pos < psl->size);

	for (int i = pos; i < psl->size - 1; i++) {
		psl->a[i] = psl->a[i + 1];
	}

	psl->size --;
}


