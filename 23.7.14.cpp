#include<stdio.h>
#include<string.h>
int leng(char* s)//����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
{
    int i, j, k = 1, a = 0, num1 = 0;
    if (strlen(s) == 0)
        return 0;
    for (i = 0; i < strlen(s); i++)
    {
        k = 1;
        for (j = num1; j < i; j++)
        {
            if (s[i] == s[j])
            {
                k = 1;
                num1 = j + 1;
                break;
            }
            k++;
        }
        if (k > a)
        {
            a = k;;
        }
    }
    return a;
}
int main()
{
    char s[20];
    int a = 0;
    fgets(s, 20, stdin);
      a=  leng(s);
      printf("%d", a);
}
