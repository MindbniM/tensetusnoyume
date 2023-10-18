#include"polynomial.h"

void Interface()
{
	printf("*******************************\n");
	printf("*** 1.�ӷ� ******* 2.���� *****\n");
	printf("*** 0.�˳� ********************\n");
	printf("*******************************\n");
	printf(">>\n");
}
void ADDList1(List*p)
{
	int n;
	printf("�����һ������ʽ������>>\n");
	scanf("%d", &n);
	printf("�����һ������ʽ��ÿһ���ϵ����ָ��>>\n");
	for (int i = 0; i < n; i++)
	{
		int num, pow;
		scanf("%d%d", &num, &pow);
		AddList(p,num,pow);
	}
}
void ADDList2(List* p)
{
	int n;
	printf("����ڶ�������ʽ������>>\n");
	scanf("%d", &n);
	printf("����ڶ�������ʽ��ÿһ���ϵ����ָ��>>\n");
	for (int i = 0; i < n; i++)
	{
		int num, pow;
		scanf("%d%d", &num, &pow);
		AddList(p, num, pow);
	}
}
void Print(List* p)
{
	if (p->next == NULL)
	{
		printf("\n");
		return;
	}
	printf("%dx^%d",p->next-> num, p->next->pow);
	p = p->next;
	while (p->next != NULL)
	{
		Prin(p->next->num, p->next->pow);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	List* polynomial1 = InitList();
	List* polynomial2 = InitList();
	ADDList1(polynomial1);
	ADDList2(polynomial2);
	system("cls");
	printf("��һ������ʽΪ>>");
	Print(polynomial1);
	printf("�ڶ�������ʽΪ>>");
	Print(polynomial2);
	printf("\n");
	int cout;
	do
	{
	    Interface();
		scanf("%d", &cout);
		switch (cout)
		{
		case ADD:
		{
			Add(polynomial1, polynomial2);
			break;
		}
		case SUB:
		{
			Sub(polynomial1, polynomial2);
			break;
		}
		case EXIT:
		{
			Listfree(polynomial1);
			polynomial1 = NULL;
			Listfree(polynomial2);
			polynomial2 = NULL;
			break;
		}
		default:
		{
			printf("ѡ�����\n");
			break;
		}
		}

	} while (cout);
	return 0;
}