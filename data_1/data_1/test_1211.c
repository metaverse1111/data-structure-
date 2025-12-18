//#define _CRT_SECURE_NO_WARNINGS
#include "Seqlist_1211.h"
void SLTest01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);

	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPrint(sl);

	SLPopFront(&sl);
	SLPrint(sl);
	SLPopFront(&sl);
	SLPrint(sl);

	SLPopBck(&sl);
	SLPrint(sl);
	SLPopBck(&sl);
	SLPrint(sl);

	SLDestroy(&sl);
}


void SLTest02()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);

	SLInsert(&sl, 0, 99);
	SLInsert(&sl,sl.size, 88);
	SLPrint(sl);

	//SLErase(&sl, 0);
	//SLPrint(sl);
	//SLErase(&sl, 4);
	//SLPrint(sl);
	//SLErase(&sl, 1);
	//SLPrint(sl);

	int find = SLFind(&sl, 4);
	if (find < 0)
	{
		printf("NotFind\n");
	}
	else
	{
		printf("Find,ÏÂ±êÊÇ£º%d\n",find);
	}
	SLDestroy(&sl);

}
int main()
{
	//SLTest01();
	SLTest02();
	return 0;
}