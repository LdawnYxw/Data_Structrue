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

void SLPushBack(SLNode** head, SLNDataType x);//Î²²å
void SLPushPront(SLNode** head, SLNDataType x);//Í·²å
void SLInsert(SLNode** head, SLNode* pos, SLNDataType x); //²åÈë

SLNode* SLFind(SLNode* head,SLNDataType x);//²éÕÒ

void SLPopBack(SLNode** head);//Î²É¾
void SLPopFront(SLNode** head);//Í·É¾
void SLErase(SLNode** head, SLNode* pos);//É¾³ý

void SLInsertAfter(SLNode* pos, SLNDataType x);//Íùºó²å
void SLEraseAfter(SLNode* pos);//ÍùºóÉ¾

void SLDestroy(SLNode** head);//Çå³ý
