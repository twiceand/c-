#define N   11
// 参考点表，存储 (x, y) 对
int table[N][2]={
    {0,	2},
    {10,	12},
    {20,	21},
    {30,	29},
    {40,	36},
    {50,	42},
    {60,	47},
    {70,	51},
    {80,	54},
    {90,	56},
    {100,	57}
};

// 根据输入的 x 值，计算对应的 y 值
int conversion(int x)
{
    int i;
    int y;

    // 如果 x 小于最小的参考点 x 值，返回最小参考点的 y 值
    if(x<table[0][0])
    {
        return table[0][1];
    }

    // 如果 x 大于最大的参考点 x 值，返回最大参考点的 y 值
    if(x>table[N-1][0])
    {
        return table[N-1][1];
    }

    // 遍历参考点，找到 x 所在的区间
    for(i=0;i<N;i++)
    {
        if(x<=table[i][0]) // 数据按 x 排序，找到 x 前后的插值节点
        {
            // 表示 x 介于 table[i-1][0] 和 table[i][0] 之间
            break;
        }
    }

    y=table[i-1][1]+(table[i][1]-table[i-1][1])*(x-table[i-1][0])/(table[i][0]-table[i-1][0]);
    return y;
}

int main(void)
{
    printf("x=25,y=%d\r\n",conversion(25));
    printf("x=75,y=%d\r\n",conversion(75));
    return 0;
  }
