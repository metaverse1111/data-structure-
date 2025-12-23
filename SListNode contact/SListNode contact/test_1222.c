#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//void SListTest01()
//{
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->date = 1;
//
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->date = 2;
//
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->date = 3;
//
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->date = 4;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLTNode* plist = node1;
//	SLTPrint(plist);
//}

//void SListTest02()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPrint(plist);
//	//SLTPushFront(&plist, 5);
//	//SLTPrint(plist);
//	//SLTPushFront(&plist, 6);
//	//SLTPrint(plist);
//	//SLTPushFront(&plist, 7);
//	//SLTPrint(plist);
//
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//
//	//SLTNode* find = SLTFind(plist, 1);
//	//SLTInsert(&plist, find, 11);
//	//SLTPrint(plist);
//	//SLTInsertAfter(find, 11);
//	//SLTPrint(plist);
//
//	//SLTErase(&plist, find);
//	//SLTPrint(plist);
//	//SLTEraseAfter(find);
//	//SLTPrint(plist);
//
//	//if (find == NULL)
//	//{
//	//	printf("没有找到\n");
//	//}
//	//else
//	//{
//	//	printf("找到了\n");
//	//}
//
//	SListDestroy(&plist);
//	SLTPrint(plist);
//
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
	//SListTest01();
	//SListTest02();
	int op = -1;
	contact* con;
	InitContact(&con);
	do {
		menu();
		printf("请选择：\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			ModifyContact(&con);
			break;
		case 4:
			FindContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			printf("退出通讯录.....\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (op != 0);

	DestroyContact(&con);
	return 0;
}