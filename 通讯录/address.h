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

contact* Initcontact();//��ʼ��

void Extend(contact* c);//��չ�ռ�

void ADDcontauct(contact* c);//���

void Findcontact(contact* c);//����

void Delecontact(contact* c);//ɾ��һ����

void show(contact* c);//��ʾ������ϵ��

void Changecontact(contact* c);//�޸�һ����ϵ��

void Dallcontact(contact* c);//�����ϵ��

void Sortcon(contact*c);//����������

