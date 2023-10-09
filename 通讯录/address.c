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
	printf("扩展成功\n");
}
void ADDcontauct(contact* c)
{
	if (IsFull(c))
	{
		printf("通讯录已满,请扩展\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", (c)->arr[(c)->num].name);
	printf("请输入年龄:");
	scanf("%d", &((c)->arr[(c)->num].age));
	printf("请输入性别:");
	scanf("%s", (c)->arr[(c)->num].sex);
	printf("请输入电话:");
	scanf("%s", (c)->arr[(c)->num].tele);
	printf("请输入地址:");
	scanf("%s", (c)->arr[(c)->num].addr);
	(c)->num++;
	printf("添加成功\n");
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
	printf("输入要查找的人名\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if ( ret== -1)
	{
		printf("没找到\n");
		return;
	}
	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		(c)->arr[ret].name, (c)->arr[ret].age, (c)->arr[ret].sex, (c)->arr[ret].tele, (c)->arr[ret].addr);
}
void Delecontact(contact* c)
{
	char Fname[NAME_MAX];
	printf("输入要删除的人名\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if (ret == -1)
	{
		printf("没有这个人\n");
		return;
	}
	for (int i = ret; i < (c)->num; i++)
	{
		(c)->arr[i] = (c)->arr[i + 1];
	}
	(c)->num--;
	printf("删除成功\n");
}
void show(contact* c)
{
	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < (c)->num; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s\n",
			(c)->arr[i].name, (c)->arr[i].age, (c)->arr[i].sex, (c)->arr[i].tele, (c)->arr[i].addr);
	}
}
void Changecontact(contact* c)
{
	char Fname[NAME_MAX];
	printf("输入要修改的人名\n");
	scanf("%s", Fname);
	int ret = Find(c, Fname);
	if (ret == -1)
	{
		printf("没有这个人\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", (c)->arr[ret].name);
	printf("请输入年龄:");
	scanf("%d", &((c)->arr[ret].age));
	printf("请输入性别:");
	scanf("%s", (c)->arr[ret].sex);
	printf("请输入电话:");
	scanf("%s", (c)->arr[ret].tele);
	printf("请输入地址:");
	scanf("%s", (c)->arr[ret].addr);
	printf("修改成功\n");
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
	printf("清空成功\n");
}
void comp(const void* s1, const void* s2)
{
	return strcmp(((Node*)s1)->name, ((Node*)s2)->name);
}
void Sortcon(contact* c)
{
	qsort((c)->arr, (c)->num, sizeof(Node), comp);
	printf("排序完成\n");
}
void Txtputcontact(contact* c)
{
	FILE* con=fopen("通讯录.txt", "w");
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
	printf("写入文件成功\n");
}
void Txtgetcontact(contact* c)
{
	FILE* con = fopen("通讯录.txt", "r");
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
			printf("通讯录已满,请扩展\n");
			return;
		}
	}
	fclose(con);
	printf("读取文件成功\n");
}
void Txtcatcontact(contact* c)
{
	FILE* con = fopen("通讯录.txt", "a");
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
	printf("追加数据成功\n");
}