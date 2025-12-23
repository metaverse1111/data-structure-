#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "contact.h"

typedef PeoInfo SLDateType;

typedef struct SListNode {
	SLDateType date;
	struct SListNode* next;
}SLTNode;

void SListInit(SLTNode** pphead);


void SLTPrint(SLTNode* phead);

void SLTPushBack(SLTNode** phead, SLDateType x);

void SLTPushFront(SLTNode** pphead, SLDateType x);

void SLTPopBack(SLTNode** pphead); 

void SLTPopFront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLDateType x);

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDateType x);

void SLTInsertAfter(SLTNode* pos, SLDateType x);

void SLTErase(SLTNode** pphead, SLTNode* pos);

void SLTEraseAfter(SLTNode* pos);

void SListDestroy(SLTNode** pphead);