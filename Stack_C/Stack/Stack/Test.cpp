#include"Stack.h"

int main() {

	ST p;

	STInit(&p);

	STPush(&p, 1);
	STPush(&p, 3);
	STPush(&p, 1);
	STPush(&p, 4);

	while (!STEmpty(&p)) {
		printf("%d %d \n", STTop(&p), STSize(&p));
		STPop(&p);
	}

	STDestroy(&p);

	return 0;
}