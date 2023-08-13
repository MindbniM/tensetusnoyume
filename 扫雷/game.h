#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS
#define hang 9//长度

#define lie 9//宽度

#define hangs hang+2

#define lies lie+2

#define zhadan 10//雷子的数量

void initialize(char ar[hang][lie], char er[hangs][lies] );//初始化

void bomds(char er[hangs][lies], int a);//放雷子

void par(char ar[hang][lie]);//打印

int handle(char ar[hang][lie],char er[hangs][lies],int a,int b);//主要内容

int look(char er[hangs][lies], int a, int b);//判断周围雷子的数量

void put();//游戏循环

void open(char ar[hang][lie], char er[hang][lie], int a, int b,int sum);//开空格
