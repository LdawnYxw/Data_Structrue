#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* a;
	size_t size; //有效数据
	size_t capacity; //空间容量
}SL;

void SLInit(SL* psl);//初始化
void SLDestroy(SL* psl); //销毁

void SLPrint(SL* psl);//打印
void SLCheckCapacity(SL* psl);//扩容

void SLPushBack(SL* psl, SLDataType x);//尾插
void SLPushFront(SL* psl, SLDataType x);//头插

void SLPopBack(SL* psl);//尾删
void SLPopFront(SL* psl);//头删

int SLFind(SL* psl, SLDataType x);//找到第一个和x相等的下标
void SLInsert(SL* psl, int pos, SLDataType x);//插入
void SLErase(SL* psl, int pos);//删除