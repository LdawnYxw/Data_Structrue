#include"Stack.h"

void STInit(ST* pst) {
	
	assert(pst);

	pst->a = NULL;
	pst->top = -1;
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x) {

	assert(pst);

	if (pst->top == pst->capacity - 1) {
		int newcapacity = (pst->capacity == 0 ? 4 : pst->capacity * 2);
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[++pst->top] = x;
}

void STPop(ST* pst) {

	assert(pst);
	assert(pst->top >= 0);

	pst->top--;
}

STDataType STTop(ST* pst) {

	assert(pst);

	assert(pst->top >= 0);

	return pst->a[pst->top];
}

bool STEmpty(ST* pst) {

	assert(pst);

	return pst->top < 0;
}

int STSize(ST* pst) {

	assert(pst);

	return pst->top + 1;
}

void STDestroy(ST* pst) {

	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = -1;
	pst->capacity = 0;
}