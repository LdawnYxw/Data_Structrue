#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode {
	QueueDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* head;
	QNode* back;
	int size;
}Queue;

void QueueInit(Queue* pst);
void QueueDestroy(Queue* pst);

void QueuePush(Queue* pst, QueueDataType x);
void QueuePop(Queue* pst);

QueueDataType QueueFront(Queue* pst);
QueueDataType QueueBack(Queue* pst);

bool QueueEmpty(Queue* pst);
int QueueSize(Queue* pst);