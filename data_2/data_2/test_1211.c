#include "Seqlist_1211.h"
//void SLTest01()
//{
//	SL sl;
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);
//
//	SLPushFront(&sl, 5);
//	SLPushFront(&sl, 6);
//	SLPrint(sl);
//
//	SLPopFront(&sl);
//	SLPrint(sl);
//	SLPopFront(&sl);
//	SLPrint(sl);
//
//	SLPopBck(&sl);
//	SLPrint(sl);
//	SLPopBck(&sl);
//	SLPrint(sl);
//
//	SLDestroy(&sl);
//}
//
//
//void SLTest02()
//{
//	SL sl;
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);
//
//	SLInsert(&sl, 0, 99);
//	SLInsert(&sl,sl.size, 88);
//	SLPrint(sl);
//
//	//SLErase(&sl, 0);
//	//SLPrint(sl);
//	//SLErase(&sl, 4);
//	//SLPrint(sl);
//	//SLErase(&sl, 1);
//	//SLPrint(sl);
//
//	int find = SLFind(&sl, 4);
//	if (find < 0)
//	{
//		printf("NotFind\n");
//	}
//	else
//	{
//		printf("Find,下标是：%d\n",find);
//	}
//	SLDestroy(&sl);
//
//}

//void ContactTest01()
//{
//	Contact con;
//	ContactInit(&con);
//	ContactDestory(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	//ContactDel(&con);
//	ContactModify(&con);
//	ContactShow(&con);
//	ContactFind(&con);
//
//	ContactDestory(&con);
//}

void menu()
{
	printf("***************通讯录**************\n");
	printf("*******1.增加         2.删除*******\n");
	printf("*******3.修改         4.查找*******\n");
	printf("*******5.展示         0.退出*******\n");
	printf("***********************************\n");

}

int main()
{
	//SLTest01();
	//SLTest02();
	//ContactTest01();
	int op = -1;
	Contact con;
	ContactInit(&con);

	do {
		menu();
		printf("请选择：\n");
		scanf("%d",&op);

		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出通讯录.....\n");
		default:
			printf("输入错误\n");
			break;
		}
	}while(op != 0);

	ContactDestory(&con);
	return 0;
}