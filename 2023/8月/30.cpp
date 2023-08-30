#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
	
	(*(void (*)())0)();
	//(void (*)())0,这是强制类型转换,将0转换为函数指针类型,我们令这个等于p
	//(*p)();这样就可以很好理解了,就是一次函数调用



	void (*signal(int, void(*)(int)))(int);
	//我们可以自定义一下类型方便理解
	typedef void(*p)(int);//将这个函数指针类型命名为p
	//那么就可以变成
	p signal(int, p);




	return 0;
}