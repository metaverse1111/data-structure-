#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include "seqlist_1211.h"
void ContactInit(Contact* con)
{
	SLInit(con);
}

void ContactDestory(Contact* con)
{
	SLDestroy(con); 
}

void ContactAdd(Contact* con)
{
	perInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人住址：\n");
	scanf("%s", info.addr);

	SLPushBack(con, info);
}

int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("删除失败\n");
		return;
	}

	SLErase(con, find);
	printf("删除成功\n");
}

void ContactModify(Contact* con)
{
	char name[NAME_MAX];	
	printf("请输入要修改的联系人姓名:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("修改失败\n");
		return;
	}

	printf("请输入修改姓名：\n");
	scanf("%s", con->arr[find].name);

	printf("请输入修改性别：\n");
	scanf("%s", con->arr[find].gender);	

	printf("请输入修改年龄：\n");
	scanf("%d", &con->arr[find].age);

	printf("请输入修改电话：\n");
	scanf("%s", con->arr[find].tel);

	printf("请输入修改住址：\n");
	scanf("%s", con->arr[find].addr);

	printf("修改成功\n");

}

void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("查找失败\n");
		return;
	}

	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%s %s %d %s %s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr
	);
}

void ContactShow(Contact* con)
{
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s %s %d %s %s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr
		);
	}
} 