#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLTDataType;

typedef struct DList{
	struct DList* next;
	struct DList* prev;
	DLTDataType val;
}DLNode;

DLNode* DLInit();

void DLPrint(DLNode* head);

void DLPushBack(DLNode* head, DLTDataType x);
void DLPushPront(DLNode* head, DLTDataType x);
void DLInsert(DLNode* pos, DLTDataType x);

DLNode* DLFind(DLNode* head, DLTDataType x);

void DLPopBack(DLNode* head);
void DLPopFront(DLNode* head);
void DLErase(DLNode* pos);

void DLDestroy(DLNode* head);