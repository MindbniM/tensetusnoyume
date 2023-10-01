#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

#define NAME_MAX 10
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define SPACE 10

typedef struct Node
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}Node;
typedef struct contact
{
	int num;
	int sz;
	Node arr[];
}contact;

contact* Initcontact();//初始化

void Extend(contact* c);//扩展空间

void ADDcontauct(contact* c);//添加

void Findcontact(contact* c);//查找

void Delecontact(contact* c);//删除一个人

void show(contact* c);//显示所有联系人

void Changecontact(contact* c);//修改一个联系人

void Dallcontact(contact* c);//清空联系人

void Sortcon(contact*c);//按名称排序

