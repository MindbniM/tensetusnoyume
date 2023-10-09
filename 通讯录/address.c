#include"address.h"
contact* Initcontact()
{
	contact* pc = (contact*)malloc(sizeof(contact) + SPACE * sizeof(Node));
	if (pc == NULL)
	{
		perror("malloc:");
		return;
	}
	pc->sz = SPACE;
	pc->num = 0;
	return pc;
}
int IsFull(contact* c)
{
	return c->num == c->sz;
}
void Extend(contact* c)
{
	assert(c);
	size_t Sz = sizeof(contact) + (c)->sz * sizeof(Node);
	size_t newSize = sizeof(contact) + ((c)->sz + SPACE) * sizeof(Node);
	contact* pc = (contact*)malloc(newSize);
	if (pc == NULL)
	{
		perror("realloc:");
		return;
	}
	memmove(pc,c, Sz);
	free(c);
	c = pc;
	(c)->sz += SPACE;
	printf("��չ�ɹ�\n");
}
void ADDcontauct(contact* c)
{
	if (IsFull(c))
	{
		printf("ͨѶ¼����,����չ\n");
		return;
	}
	printf("����������:");
	scanf("%s", (c)->arr[(c)->num].name);
	printf("����������:");
	scanf("%d", &((c)->arr[(c)->num].age));
	printf("�������Ա�:");
	scanf("%s", (c)->arr[(c)->num].sex);
	printf("������绰:");
	scanf("%s", (c)->arr[(c)->num].tele);
	printf("�������ַ:");
	scanf("%s", (c)->arr[(c)->num].addr);
	(c)->num++;
	printf("��ӳɹ�\n");
}
int Find(contact* c, char* s)
{
	for (int i = 0; i < (c)->num; i++)
	{
		if (strcmp((c)->arr[i].name, s) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Findcontact(contact* c)
{
	char Fname[NAME_MAX];
	printf("����Ҫ���ҵ�����\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if ( ret== -1)
	{
		printf("û�ҵ�\n");
		return;
	}
	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		(c)->arr[ret].name, (c)->arr[ret].age, (c)->arr[ret].sex, (c)->arr[ret].tele, (c)->arr[ret].addr);
}
void Delecontact(contact* c)
{
	char Fname[NAME_MAX];
	printf("����Ҫɾ��������\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if (ret == -1)
	{
		printf("û�������\n");
		return;
	}
	for (int i = ret; i < (c)->num; i++)
	{
		(c)->arr[i] = (c)->arr[i + 1];
	}
	(c)->num--;
	printf("ɾ���ɹ�\n");
}
void show(contact* c)
{
	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < (c)->num; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s\n",
			(c)->arr[i].name, (c)->arr[i].age, (c)->arr[i].sex, (c)->arr[i].tele, (c)->arr[i].addr);
	}
}
void Changecontact(contact* c)
{
	char Fname[NAME_MAX];
	printf("����Ҫ�޸ĵ�����\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if (ret == -1)
	{
		printf("û�������\n");
		return;
	}
	printf("����������:");
	scanf("%s", (c)->arr[ret].name);
	printf("����������:");
	scanf("%d", &((c)->arr[ret].age));
	printf("�������Ա�:");
	scanf("%s", (c)->arr[ret].sex);
	printf("������绰:");
	scanf("%s", (c)->arr[ret].tele);
	printf("�������ַ:");
	scanf("%s", (c)->arr[ret].addr);
	printf("�޸ĳɹ�\n");
}
void Dallcontact(contact* c)
{
	contact* pc = (contact*)malloc(sizeof(contact) + SPACE * sizeof(Node));
	if (pc == NULL)
	{
		perror("malloc:");
		return;
	}
	(c)->sz = SPACE;
	(c)->num = 0;
	printf("��ճɹ�\n");
}
void comp(const void* s1, const void* s2)
{
	return strcmp(((Node*)s1)->name, ((Node*)s2)->name);
}
void Sortcon(contact* c)
{
	qsort((c)->arr, (c)->num, sizeof(Node), comp);
	printf("�������\n");
}
void Txtputcontact(contact* c)
{
	FILE* con=fopen("ͨѶ¼.txt", "w");
	if (con == NULL)
	{
		perror("fopen:");
		return;
	}
	for (int i = 0; i < (c)->num; i++)
	{
		fprintf(con,"%-20s%-5d%-5s%-12s%-30s\n",
			(c)->arr[i].name, (c)->arr[i].age, (c)->arr[i].sex, (c)->arr[i].tele, (c)->arr[i].addr);
	}
	fclose(con);
	printf("д���ļ��ɹ�\n");
}
void Txtgetcontact(contact* c)
{
	FILE* con = fopen("ͨѶ¼.txt", "r");
	if (con == NULL)
	{
		perror("fopen:");
		return;
	}
	for (int i = 0; fscanf(con, "%s%d%s%s%s\n",
		c->arr[i].name, &(c->arr[i].age), c->arr[i].sex, c->arr[i].tele, c->arr[i].addr) != EOF;
		i++)
	{
		c->num += 1;
		if (IsFull(c))
		{
			printf("ͨѶ¼����,����չ\n");
			return;
		}
	}
	fclose(con);
	printf("��ȡ�ļ��ɹ�\n");
}
void Txtcatcontact(contact* c)
{
	FILE* con = fopen("ͨѶ¼.txt", "a");
	if (con == NULL)
	{
		perror("fopen:");
		return;
	}
	for (int i = 0; i < (c)->num; i++)
	{
		fprintf(con, "%-20s%-5d%-5s%-12s%-30s\n",
			(c)->arr[i].name, (c)->arr[i].age, (c)->arr[i].sex, (c)->arr[i].tele, (c)->arr[i].addr);
	}
	fclose(con);
	printf("׷�����ݳɹ�\n");
}