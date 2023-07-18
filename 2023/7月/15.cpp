
#include"10.h"

struct Store
{
	char name[50];
	float area;
	char date[20];
	float fee;
	float sales;
};
typedef struct Store ElemType;//把合法的变量名转化为类型

typedef struct DuNode   //双向链表节点的结构体定义，使用 typedef 关键字来定义结构体类型 DuNode
{
	ElemType data;  // int data;
	struct DuNode* prev;
	struct DuNode* next;
}DuNode;
typedef struct
{
	struct DuNode* head;
	int cursize;
}DuLinkList;         //该结构体名为DuLinkList

struct DuNode* Buynode(struct DuNode* parg = nullptr, struct DuNode* narg = nullptr)//创建并返回一个双向链表节点。
{
	struct DuNode* s = (struct DuNode*)malloc(sizeof(struct DuNode));
	if (nullptr == s) exit(EXIT_FAILURE);
	s->prev = (parg == nullptr ? s : parg);
	s->next = (narg == nullptr ? s : narg);
	return s;
}
void Freenode(struct DuNode* p)  //将传入的节点释放
{
	free(p);
}
void InitList(DuLinkList* plist)   //初始化双向链表
{
	assert(plist != nullptr);
	plist->head = Buynode();     //创建一个新的节点，并将返回的节点指针赋值给头指针
	plist->cursize = 0;         //将链表的当前大小 cursize 初始化为 0
}

int GetSize(DuLinkList* plist)   //返回链表的大小
{
	assert(plist != nullptr);
	return plist->cursize;
}
bool Is_Empty(DuLinkList* plist)     //判断链表是否为空
{
	assert(plist != nullptr);
	return GetSize(plist) == 0;
}



void FindValue(DuLinkList* plist, char* s)  //查找指定数据
{
	assert(plist != nullptr);
	struct DuNode* p = plist->head->next;

	while (p != plist->head && strcmp(p->data.name, s) != 0)
	{
		p = p->next;
	}
	if (p == plist->head)
	{
		printf("没找到");
	}
	else
	{
		printf("店铺名字: %s 店铺位置: %.0f 加盟日期:%s 加盟费: %.0f 销售额：%.0f\n",
			p->data.name, p->data.area, p->data.date, p->data.fee, p->data.sales);
	}


}
void findmax(DuLinkList* plist)  //输出最大营业额的信息
{
	assert(plist != nullptr);

	// 空链表处理
	if (plist->head->next == plist->head) {
		printf("暂无加盟店数据\n");
		return;
	}
	struct DuNode* p = plist->head->next; //定义一个p使它指向链表中头节点的下一个，因为头结点中没有date
	float max = p->data.sales;  // 假设第一个元素为最大值
	while (p != plist->head)
	{
		if (p->data.sales > max) {
			max = p->data.sales;  // 找到更大的值

		}
		p = p->next;
	}
	printf("下面是销售额最高的加盟店数据\n");
	p = plist->head->next; // 将指针p重新指向链表头结点

	while (p != plist->head)
	{
		if (p->data.sales == max) {

			printf("店铺名字: %s 店铺面积: %.0f 加盟日期:%s 加盟费: %.0f 销售额：%.0f\n",
				p->data.name, p->data.area, p->data.date, p->data.fee, p->data.sales);

		}
		p = p->next;

	}



}

void ModifyValue(DuNode* p)             //修改数据的主体函数
{


	// 修改店铺名字
	char newName[100];
	printf("请输入新的店铺名字：");
	scanf("%s", newName);
	strcpy(p->data.name, newName);

	// 修改其他属性，根据需要继续添加相应的代码

	// 示例：修改店铺地址
	float newarea;
	printf("请输入新的店铺面积：");
	scanf_s("%f", &newarea);
	p->data.area = newarea;

	// 示例：修改店铺联系电话
	char newdate[100];
	printf("请输入新的日期：");
	scanf("%s", &newdate);
	strcpy(p->data.date, newdate);

	float newfee;
	printf("请输入新的加盟费：");
	scanf("%f", &newfee);
	p->data.fee = newfee;

	float newsales;
	printf("请输入新的销售额：");
	scanf("%f", &newsales);
	p->data.sales = newsales;
}


void Modify(DuLinkList* plist)       //修改数据
{
	assert(plist != nullptr);

	// 空链表处理
	if (plist->head->next == plist->head)
	{
		printf("没有加盟店数据\n");
		return;
	}
	struct DuNode* p = plist->head->next; //定义一个p使它指向链表中头节点的下一个，因为头结点中没有date
	char data_[100];
	printf("请输入要修改的店铺名字：");
	scanf("%s", data_);

	while (p != plist->head)//查找要修改数据的位置
	{
		if (strcmp(p->data.name, data_) == 0) 
		{
			ModifyValue(p);
			printf("已成功修改加盟店信息。\n");
			return;
		}


		p = p->next;
	}
	printf("未找到该店铺数据");
}

void count1000(DuLinkList* plist)   //计算面积大于1000的店铺所占的百分比
{
	double num = 0;
	assert(plist != nullptr);

	// 空链表处理
	if (plist->head->next == plist->head) {
		printf("没有加盟店数据\n");
		return;
	}
	struct DuNode* p = plist->head->next;
	while (p != plist->head)     //整个链表循环一次
	{
		if (p->data.sales >= 1000)
		{
			num++;
		}

		p = p->next;
	}
	int size = GetSize(plist);
	double a = num / size;
	printf("营业额>=1000的店面所占总店面的百分比为：%.2lf%%", a * 100);     //转义字符"%%"表示打印一个%

}
void aver(DuLinkList* plist)    //求平均面积
{
	double num = 0;
	assert(plist != nullptr);

	// 空链表处理
	if (plist->head->next == plist->head) 
	{
		printf("没有加盟店数据\n");
		return;
	}
	struct DuNode* p = plist->head->next;
	double s = 0;
	while (p != plist->head)     //整个链表循环一次
	{

		s = s + p->data.area;
		p = p->next;
	}
	int size = GetSize(plist);
	double aver = s / size;
	printf("加盟店平均面积为%.2lf", aver);
}
void ShowStore(DuLinkList* plist)     //打印所有数据
{
	assert(plist);
	struct DuNode* p = plist->head->next; //
	if (p == plist->head)
	{
		printf("无店铺数据");
		return;
	}
	while (p != plist->head)
	{
		printf("店铺名字: %5s 店铺位置: %5.0f 加盟日期:%5s 加盟费: %5.0f 销售额：%4.0f\n",
			p->data.name, p->data.area, p->data.date, p->data.fee, p->data.sales);
		p = p->next;
	}
	printf("----------------------------------------------\n");
}





bool InsertNode(DuLinkList* plist, struct DuNode* ptr, ElemType val) //插入节点，在push-back中会用到
{
	assert(plist != nullptr);
	if (nullptr == ptr) return false;
	ptr->prev = Buynode(ptr->prev, ptr);  //开辟一个节点，前驱节点设置为 ptr->prev，后继节点设置为 ptr
	struct DuNode* newnode = ptr->prev;     //开辟的节点给newnode用
	newnode->prev->next = newnode;          //将newnode前面的那个节点和newnode绑起来
	newnode->data = val;
	plist->cursize += 1;
	return true;
}
bool Push_back(DuLinkList* plist, ElemType val)   //向双链表尾部添加节点 
{
	return InsertNode(plist, plist->head, val);
}
bool Push_front(DuLinkList* plist, ElemType val)    //向双链表头部添加节点，作业中不会用到
{
	return InsertNode(plist, plist->head->next, val);
}

bool EraseList(DuLinkList* plist, struct DuNode* p)   //删除节点，DuNode* p为要删除的节点
{
	assert(plist != nullptr);
	if (nullptr == p || plist->head == p) return false;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	Freenode(p);
	plist->cursize -= 1;
	return true;
}
//下面两个作业中不会用到
bool Pop_back(DuLinkList* plist)   //删除链表尾部的节点，传入的参数是链表头节点的前一个节点（即尾节点
{
	return EraseList(plist, plist->head->prev);
}
bool Pop_front(DuLinkList* plist)   //删除链表头部的节点，传入的参数是链表头节点的下一个节点（即首节点）。
{
	return EraseList(plist, plist->head->next);
}

bool RemoveList(DuLinkList* plist, char* s)  //case5所对应的删除链表的函数
{
	assert(plist != nullptr);

	// 空链表处理
	if (plist->head->next == plist->head) {
		printf("没有店铺信息\n");
		return 0;
	}
	struct DuNode* p = plist->head->next;
	while (p != plist->head && strcmp(p->data.name, s) != 0)    //寻找要删除的节点
	{
		p = p->next;
	}
	if (p == plist->head)
	{
		printf("没找到该店铺");
	}
	else
	{
		return EraseList(plist, p);     //将该链表和要删除的节点传给 EraseList进行删除操作
		printf("删除成功");

	}


	if (p == nullptr) return false;

	return 1;
}

void ClearList(DuLinkList* plist)   //通过循环遍历链表并连续执行Pop_back()函数，直到链表为空为止
{
	assert(plist != nullptr);
	while (!Is_Empty(plist))
	{
		Pop_back(plist);           //删除链表尾部的节点，传入的参数是链表头节点的前一个节点（即尾节点
	}
}
void DestroyList(DuLinkList* plist)
{
	assert(plist != nullptr);
	ClearList(plist);               //先清空节点
	Freenode(plist->head);          //再释放节点
	plist->head = nullptr;
}

void Add(DuLinkList* plist)   //添加新的信息
{
	assert(plist != nullptr);
	struct Store tmp = {};
	printf("输入店铺信息:\n");
	printf("店铺名字: ");
	scanf("%s", tmp.name);
	printf("店铺面积: ");
	scanf("%f", &tmp.area);
	printf("加盟日期: ");
	scanf("%s", tmp.date);
	printf("加盟费: ");
	scanf("%f", &tmp.fee);
	printf("销售额: ");
	scanf("%f", &tmp.sales);
	Push_back(plist, tmp);
	printf("成功录入该加盟店数据");
}
void SaveFile(DuLinkList* plist)
{
	assert(plist != nullptr);
	FILE* fp = fopen("storelist.txt", "w");        //定义一个文件夹并打开
	if (nullptr == fp) {                           //判断是否打开成功
		printf("文件打开失败\n");
		return;
	}

	fprintf(fp, "%d\n", GetSize(plist));   //        函数获取链表大小并写入

	struct DuNode* p = plist->head->next;

	while (p != plist->head)
	{
		struct Store tmp = p->data;
		fprintf(fp, "%s %f %s %f %f\n", tmp.name, tmp.area, tmp.date, tmp.fee, tmp.sales);
		printf("上传至文件夹成功");
		p = p->next;
	}

	fclose(fp);
}
void LoadFile(DuLinkList* plist)
{
	assert(plist != nullptr);
	FILE* fp = fopen("storelist.txt", "r");        //定义一个文件夹并打开
	if (nullptr == fp) {                           //判断是否打开成功
		printf("文件打开失败\n");
		return;
	}
	int num = 0;
	fscanf(fp, "%d", &num);   //        函数获取链表大小并写入



	for (int i = 0; i < num; ++i)
	{
		ElemType tmp;
		fscanf(fp, "%s %f %s %f %f\n", tmp.name, &(tmp.area), tmp.date, &(tmp.fee), &(tmp.sales));
		Push_back(plist, tmp);
	}

	printf("成功从文件中加载店铺数据");
	fclose(fp);
	fp = nullptr;
}

int MainMenu()
{


	int select = 0;
	printf("\n\n\n\n");
	printf("\t\t|-----------------加盟店管理系统-----—-----—--------|\n");
	printf("\t\t|\t\t\t\t\t            |\n");
	printf("\t\t|\t\t1.录入加盟店记录                    |\n");
	printf("\t\t|\t\t2.查找指定加盟店                    |\n");
	printf("\t\t|\t\t3.查找销售额最高                    |\n");
	printf("\t\t|\t\t4.修改指定加盟店数据                |\n");
	printf("\t\t|\t\t5.删除指定加盟店数据                |\n");
	printf("\t\t|\t\t6.统计>1000百分比                   |\n");
	printf("\t\t|\t\t7.统计加盟店的平均店面积            |\n");
	printf("\t\t|\t\t8.打印所有加盟店数据                |\n");
	printf("\t\t|\t\t9.上传至文件夹或从文件中加载数据    |\n");
	printf("\t\t|\t\t0.退出\t                            |\n");
	printf("\t\t|\t\t\t\t\t            |\n");
	printf("\t\t|---------------------------------------------------|\n\n");
	printf("\t\t\t请选择（0-9）：");
	scanf("%d", &select);
	return select;
}


int main()
{
	system("color f0\n");
	DuLinkList storelist;    //定义一个头节点
	InitList(&storelist);    //初始化头节点
	int select;
	do
	{
		select = MainMenu();
		switch (select)
		{
		case 0: break;
		case 1:

			Add(&storelist);
			break;
		case 2:
			char data_[100];

			printf("请输入店铺名字：");
			scanf("%s", data_);
			FindValue(&storelist, data_);
			break;
		case 3:

			findmax(&storelist);
			break;
		case 4:
			Modify(&storelist);
			break;

		case 5:
			char data_2[100];

			printf("请输入要删除的店铺名字：");
			scanf("%s", data_2);
			RemoveList(&storelist, data_2);
			break;
		case 6:

			count1000(&storelist);
			break;
		case 7:

			aver(&storelist);
			break;
		case 8:
			ShowStore(&storelist);
			break;

		case 9:

			printf("请选择：\n1.将数据上传至文件夹\n2.从文件中加载店铺数据");
			int choose;
			scanf("%d", &choose);
			switch (choose)
			{
			case 1:	SaveFile(&storelist);
				break;
			case 2:LoadFile(&storelist);
				break;
			}

			break;
		default:
			printf("选择错误 .... \n");
		}
	} while (select != 0);

	DestroyList(&storelist);  //清空链表
	return 0;
}
