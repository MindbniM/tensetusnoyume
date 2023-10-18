#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>

typedef int type;
typedef struct List
{
	type num;
	type pow;
	struct List* next;
}List;

enum
{
	EXIT,
	ADD,
	SUB,
};

List* InitList();

void AddList(List* p,int num,int pow);

void Add(List* p1, List* p2);

void Prin(type num, type pow);

void Print(List* p);

void Sub(List* p1, List* p2);

void Listfree(List* p);
