#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<assert.h>
//void CONS(const size_t num)//打印num的二进制补码
//{
//	if (num)
//	{
//		CONS(num / 2);
//		printf("%d ", num % 2);
//	}
//	else
//		return;
//}
//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//union A
//{
//	int a;
//	char b;
//};
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));

	/*printf("%d", sizeof(A));*/
	//struct S
	//{
	//	char a : 3;
	//	char b : 4;
	//	char c : 5;
	//	char d : 4;
	//};
	//struct S s = { 0 };
	//s.a = 10;//1010
	//s.b = 12;//1100
	//s.c = 3;//11
	//s.d = 4;//100
	/*printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);
	printf("%d\n", Thur);
	printf("%d\n", Fri);
	printf("%d\n", Sat);
	printf("%d\n", Sun);*/
}
