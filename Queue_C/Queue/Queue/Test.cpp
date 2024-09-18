#include"Queue.h"

int main() {
	
	Queue pst;

	QueueInit(&pst);

	QueuePush(&pst, 1);
	QueuePush(&pst, 3);
	QueuePush(&pst, 1);
	QueuePush(&pst, 4);

	printf("%d\n", QueueBack(&pst));
	printf("%d\n", QueueSize(&pst));

	while (!QueueEmpty(&pst)) {
		printf("%d ", QueueFront(&pst));
		QueuePop(&pst);
	}

	QueueDestroy(&pst);


	return 0;
}