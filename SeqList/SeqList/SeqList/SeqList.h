#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* a;
	size_t size; //��Ч����
	size_t capacity; //�ռ�����
}SL;

void SLInit(SL* psl);//��ʼ��
void SLDestroy(SL* psl); //����

void SLPrint(SL* psl);//��ӡ
void SLCheckCapacity(SL* psl);//����

void SLPushBack(SL* psl, SLDataType x);//β��
void SLPushFront(SL* psl, SLDataType x);//ͷ��

void SLPopBack(SL* psl);//βɾ
void SLPopFront(SL* psl);//ͷɾ

int SLFind(SL* psl, SLDataType x);//�ҵ���һ����x��ȵ��±�
void SLInsert(SL* psl, int pos, SLDataType x);//����
void SLErase(SL* psl, int pos);//ɾ��