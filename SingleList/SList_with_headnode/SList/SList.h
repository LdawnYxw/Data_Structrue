#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLNDataType;

typedef struct SListNode {
	SLNDataType val;
	struct SListNode* next;
}SLNode;

void SLPrint(SLNode* head);

void SLPushBack(SLNode* head, SLNDataType x);
void SLPushPront(SLNode* head, SLNDataType x);

SLNode* SLFind(SLNode* head, SLNDataType x);

void SLInsert(SLNode* head, SLNode* pos, SLNDataType x);

void SLPopBack(SLNode* head);
void SLPopFront(SLNode* head);
void SLErase(SLNode* head, SLNode* pos);

void SLDestroy(SLNode* head);