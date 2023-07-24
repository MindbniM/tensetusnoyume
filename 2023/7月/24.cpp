#include "game.h"
void show()
{
    printf("***************************\n");
    printf("********  1.play  *********\n");
    printf("********  0.over  *********\n");
    printf("***************************\n");
}
int main()
{
    int a;
    do
    {
        show();
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出\n");
            break;
        default:
            printf("输入错误,重新输入");
            break;
        }
    } while (a);
    return 0;
}