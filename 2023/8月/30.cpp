#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
	
	(*(void (*)())0)();
	//(void (*)())0,����ǿ������ת��,��0ת��Ϊ����ָ������,�������������p
	//(*p)();�����Ϳ��Ժܺ������,����һ�κ�������



	void (*signal(int, void(*)(int)))(int);
	//���ǿ����Զ���һ�����ͷ������
	typedef void(*p)(int);//���������ָ����������Ϊp
	//��ô�Ϳ��Ա��
	p signal(int, p);




	return 0;
}