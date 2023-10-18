#include"polynomial.h"

List* InitList()
{
	List* p = (List*)malloc(sizeof(List));
	if (p == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	p->next = NULL;
	return p;
}

void Prin(type num, type pow)
{
	if (num > 0)
	{
		printf("+%dx^%d", num, pow);
	}
	else if(num<0)
	{
		printf("%dx^%d", num, pow);
	}
}
void AddList(List* p,int num,int pow)
{
	assert(p);
	if (num == 0)
		return;
	while (p->next != NULL)
	{
		if (p->next->pow == pow)
		{
			p->next->num += num;
			return;
		}
		if (p->next->pow > pow)
		{
			List* pl = (List*)malloc(sizeof(List));
			if (pl == NULL)
			{
				perror("malloc:");
				return;
			}
			pl->num = num;
			pl->pow = pow;
			List* LI = p->next;
			p->next = pl;
			pl->next = LI;
			return;
		}
		p = p->next;
	}
	List* pl = (List*)malloc(sizeof(List));
	if (pl == NULL)
	{
		perror("malloc:");
		return;
	}
	pl->num = num;
	pl->pow = pow;
	pl->next = NULL;
	p->next = pl;
}

void Add(List* p1, List* p2)
{
	printf("相加结果为>>\n");
	if (p1->next == NULL)
	{
		Print(p2);
		printf("\n");
		return;
	}
	if (p2->next == NULL)
	{
		Print(p1);
		printf("\n");
		return;
	}
	if (p1->next->pow < p2->next->pow)
	{
		printf("%dx^%d", p1->next->num, p1->next->pow);
		p1 = p1->next;
	}
	else if (p1->next->pow > p2->next->pow)
	{
		printf("%dx^%d", p2->next->num, p2->next->pow);
		p2 = p2->next;
	}
	else
	{
		printf("%dx^%d", p1->next->num+p2->next->num, p1->next->pow);
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1->next != NULL && p2->next != NULL)
	{
		if (p1->next->pow < p2->next->pow)
		{
			Prin(p1->next->num, p1->next->pow);
			p1 = p1->next;
		}
		else if (p1->next->pow > p2->next->pow)
		{
			Prin(p2->next->num, p2->next->pow);
			p2 = p2->next;
		}
		else
		{
			Prin(p1->next->num + p2->next->num, p1->next->pow);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1->next == NULL)
	{
		while (p2->next != NULL)
		{
			Prin(p2->next->num, p2->next->pow);
			p2 = p2->next;
		}
		printf("\n");
		return;
	}
	if (p2->next == NULL)
	{
		while (p1->next != NULL)
		{
			Prin(p1->next->num, p1->next->pow);
			p1 = p1->next;
		}
		printf("\n");
		return;
	}
}
void subList(List* p)
{
	if (p == NULL)
		return;
	while (p->next != NULL)
	{
		p->next->num = 0-(p->next->num);
		p = p->next;
	}
}
void Sub(List* p1, List* p2)
{
	assert(p1 && p2);
	printf("相减结果为>>\n");
	subList(p2);
	if (p1->next == NULL)
	{
		Print(p2);
		printf("\n");
		return;
	}
	if (p2->next == NULL)
	{
		Print(p1);
		printf("\n");
		return;
	}
	if (p1->next->pow < p2->next->pow)
	{
		printf("%dx^%d", p1->next->num, p1->next->pow);
		p1 = p1->next;
	}
	else if (p1->next->pow > p2->next->pow)
	{
		printf("%dx^%d", p2->next->num, p2->next->pow);
		p2 = p2->next;
	}
	else
	{
		printf("%dx^%d", p1->next->num + p2->next->num, p1->next->pow);
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1->next != NULL && p2->next != NULL)
	{
		if (p1->next->pow < p2->next->pow)
		{
			Prin(p1->next->num, p1->next->pow);
			p1 = p1->next;
		}
		else if (p1->next->pow > p2->next->pow)
		{
			Prin(p2->next->num, p2->next->pow);
			p2 = p2->next;
		}
		else
		{
			Prin(p1->next->num + p2->next->num, p1->next->pow);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1->next == NULL)
	{
		while (p2->next != NULL)
		{
			Prin(p2->next->num, p2->next->pow);
			p2 = p2->next;
		}
		printf("\n");
		return;
	}
	else if (p2->next == NULL)
	{
		while (p1->next != NULL)
		{
			Prin(p1->next->num, p1->next->pow);
			p1 = p1->next;
		}
		printf("\n");
		return;
	}
}
void Listfree(List* p)
{
	if (p == NULL)
		return;
	List* Li = p;
	while (p= NULL)
	{
		List* pl = p->next;
		p = p->next;
		free(pl);
	}
	free(Li);
}
