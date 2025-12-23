<<<<<<< HEAD
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
//#define N 100
////¾²Ì¬
//struct SeqList
//{
//	int arr[N];
//	int size;
//};


//typedef int SLDataType;
typedef perInfo SLDataType;

struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
};
typedef struct SeqList SL;

void SLInit(SL* ps);

void SLDestroy(SL* ps);
void SLPrint(SL s);

void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBck(SL* ps);
void SLPopFront(SL* ps);

void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);
=======
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
//#define N 100
////¾²Ì¬
//struct SeqList
//{
//	int arr[N];
//	int size;
//};


//typedef int SLDataType;
typedef perInfo SLDataType;

struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
};
typedef struct SeqList SL;

void SLInit(SL* ps);

void SLDestroy(SL* ps);
void SLPrint(SL s);

void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBck(SL* ps);
void SLPopFront(SL* ps);

void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);
>>>>>>> d3fb88ab71e1acff83cf65b13e2cf164758e8e5f
