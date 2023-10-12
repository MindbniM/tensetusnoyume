#include"address.h"
enum function
{
	Exit,
	ADD,
	Dele,
	Find,
	Change,
	Show,
	Dall,
	Exten,
	Sort,
	GetTxt,
	PutTxt,
	CatTxt,
};
void menu()
{
	printf("************************************\n");
	printf("*** 0.exit ********* 1.add *********\n");
	printf("*** 2.dele ********* 3.find ********\n");
	printf("*** 4.change ******* 5.show ********\n");
	printf("*** 6.Dall ********* 7.exten *******\n");
	printf("*** 8.sotr ********* 9.getTxt ******\n");
	printf("*** 10.putTxt ****** 11.catTxt ******\n");
	printf("************************************\n");
}
int main()
{
	contact* con;
	con=Initcontact();
	int select;
	Txtgetcontact(con);
	do
	{
		menu();
		scanf("%d", &select);
		switch (select)
		{
		case Exit:
			Txtputcontact(con);
			free(con);
			break;
		case ADD:
			ADDcontauct(con);
			break;
		case Dele:
			Delecontact(con);
			break;
		case Find:
			Findcontact(con);
			break;
		case Change:
			Changecontact(con);
			break;
		case Show:
			show(con);
			break;
		case Dall:
			Dallcontact(con);
			break;
		case Exten:
			Extend(con);
			break;
		case Sort:
			Sortcon(con);
			break;
		case PutTxt:
			Txtputcontact(con);
			break;
		case GetTxt:
			Txtgetcontact(con);
			break;
		case CatTxt:
			Txtcatcontact(con);
			break;
		}
	} while (select);
}