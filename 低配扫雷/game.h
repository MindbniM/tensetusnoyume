#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS
#define hang 9//����

#define lie 9//���

#define hangs hang+2

#define lies lie+2

#define zhadan 10//���ӵ�����

void initialize(char ar[hang][lie], char er[hangs][lies] );//��ʼ��

void bomds(char er[hangs][lies], int a);//������

void par(char ar[hang][lie]);//��ӡar[][]

int handle(char ar[hang][lie],char er[hangs][lies],int a,int b);//��Ҫ����

void per(char er[hangs][lies]);//��ӡer[][]

int look(char er[hangs][lies], int a, int b);//�ж���Χ���ӵ�����

void put();//����ѭ��

void open(char ar[hang][lie], char er[hang][lie], int a, int b);//��û��չ����ʱû�ã�Ԥ���õݹ�ʵ�ֿ��ո�
