#pragma once
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100
typedef struct personinfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}perInfo;

struct SeqList;

typedef struct SeqList Contact;

void ContactInit(Contact* con);

void ContactDestory(Contact* con);

void ContactAdd(Contact* con);

void ContactDel(Contact* con);

void ContactModify(Contact* con);

void ContactFind(Contact* con);

void ContactShow(Contact* con);