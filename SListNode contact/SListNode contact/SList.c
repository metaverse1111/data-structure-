#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SListInit(SLTNode** pphead)
{
	*pphead = NULL;//(SLTNode*)malloc(sizeof(SLTNode));
	//(*pphead)->next = NULL;

}
  

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d->", pcur->date);
		pcur = pcur->next;
	}
	printf("NULL\n");
}


SLTNode* SLTBuyNode(SLDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}
void SLTPushBack(SLTNode** pphead, SLDateType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;

		}
		ptail->next = newnode;
	}

}

void SLTPushFront(SLTNode** pphead, SLDateType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);	
	newnode->next = *pphead;
	*pphead = newnode;

}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next; 
}

SLTNode* SLTFind(SLTNode* phead, SLDateType x)
{
	SLTNode* pcur = phead;
	while(pcur)
	{
		if (0 == strcmp(phead->date.name, x.name))
		{
			return  pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDateType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* prev = *pphead;
	SLTNode* newnode = SLTBuyNode(x);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else {
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

void SLTInsertAfter(SLTNode* pos, SLDateType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	if (pos == *pphead)
	{
		//SLTNode* next = (*pphead)->next;
		//free(pos);
		//pos = NULL;
		//*pphead = next;
		SLTPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void SListDestroy(SLTNode** pphead)
{
	if ((pphead && *pphead)==NULL)
	{
		return;
	}
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}