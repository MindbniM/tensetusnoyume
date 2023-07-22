#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define fuck 15
#define n fuck-1
int main()
{//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
    int ans[n][n];
    int c, d;
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;
    //循环圈数
    int loop = n / 2;
    //偏移数
    int offset = 1;
    //当前要添加的元素
    int count = 1;

    while (loop) {
        int i = startX;
        int j = startY;
        //模拟上侧从左到右
        for (; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //模拟右侧从上到下
        for (; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //模拟下侧从右到左
        for (; j > startY; j--) {
            ans[i][j] = count++;
        }
        //模拟左侧从下到上
        for (; i > startX; i--) {
            ans[i][j] = count++;
        }
        //偏移值每次加2
        offset += 2;
        //遍历起始位置每次+1
        startX++;
        startY++;
        loop--;
    }
    //若n为奇数需要单独给矩阵中间赋值
    if (n % 2)
        ans[mid][mid] = count;

    for ( c = 0; c < n; c++)
    {
        for ( d = 0; d < n; d++)
        {
            printf("%-5d", ans[c][d]);
        }
        printf("\n");
    }
    return 0;
}