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

void SLPushBack(SLNode** head, SLNDataType x);//β��
void SLPushPront(SLNode** head, SLNDataType x);//ͷ��
void SLInsert(SLNode** head, SLNode* pos, SLNDataType x); //����

SLNode* SLFind(SLNode* head,SLNDataType x);//����

void SLPopBack(SLNode** head);//βɾ
void SLPopFront(SLNode** head);//ͷɾ
void SLErase(SLNode** head, SLNode* pos);//ɾ��

void SLInsertAfter(SLNode* pos, SLNDataType x);//�����
void SLEraseAfter(SLNode* pos);//����ɾ

void SLDestroy(SLNode** head);//���
