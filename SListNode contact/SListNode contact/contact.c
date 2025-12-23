#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#include "SList.h"

void InitContact(contact** con)
{
	SListInit(con);
}

void DestroyContact(contact** con)
{
	SListDestroy(con);
}

void AddContact(contact** con)
{
	PeoInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.sex);

	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人住址：\n");
	scanf("%s", info.addr);

	SLTPushBack(con, info);
}

SLDateType NameFromFind(contact** con, char name[NAME_MAX])
{
	SLDateType info = { 0,0,0,0,0 };
	while (*con)
	{
		if (0 == strcmp((*con)->date.name, name))
		{
			return (*con)->date;
		}
		*con = (*con)->next;
	}
	return info;
}

void DelContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n");
	scanf("%s", name);
	SLDateType compact = NameFromFind(con, name);
	if (compact.age == 0)
	{
		printf("删除失败\n");
		return;
	}
	
	SLTNode* find = SLTFind(*con,compact);
	SLTErase(con,find);
	printf("删除成功\n");

}

void ShowContact(contact** con)  //为了形式统一，所以统一使用二级指针
{
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	contact* pcur = *con;//如果使用二级指针，那么相当于是传值调用，修改pcur也会修改con
	while (pcur)
	{
		printf("%s %s %d %s %s\n",
			(pcur)->date.name,
			(pcur)->date.sex,
			(pcur)->date.age,
			(pcur)->date.tel,
			(pcur)->date.addr
		);
		pcur = (pcur)->next;

	}
}

void FindContact(contact** con)  //为了形式统一，所以统一使用二级指针
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名:\n");
	scanf("%s", name);
	SLDateType compact = NameFromFind(con, name);
	if (compact.age == 0)
	{
		printf("查找失败\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%s %s %d %s %s\n",
		(*con)->date.name,
		(*con)->date.sex,
		(*con)->date.age,
		(*con)->date.tel,
		(*con)->date.addr
	);
}

void ModifyContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名:\n");
	scanf("%s", name);
	SLDateType compact = NameFromFind(con, name);
	if (compact.age == 0)
	{
		printf("删除失败\n");
		return;
	}
	printf("请输入修改姓名：\n");
	scanf("%s", (*con)->date.name);

	printf("请输入修改性别：\n");
	scanf("%s", (*con)->date.sex);

	printf("请输入修改年龄：\n");
	scanf("%d", &(*con)->date.age);

	printf("请输入修改电话：\n");
	scanf("%s", (*con)->date.tel);

	printf("请输入修改住址：\n");
	scanf("%s", (*con)->date.addr);

	printf("修改成功\n");
}
