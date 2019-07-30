//本文转录于https://www.cnblogs.com/kuotian/p/5351757.html

#include <stdio.h>

#define MaxN 1001
#define MinH -10001

int H[MaxN], size;

//创建最小堆
void Creat()
{
    size = 0;
    H[0] = MinH;//设置岗哨,根节点H[0]最小
}

//将X插入H.这里省略检查对是否已满的代码
void Insert(int X)
{
    int i;
    for (i = ++size; H[i/2] > X; i /= 2) //将大的元素下移,找到X的位置i
        H[i] = H[i/2];
    H[i] = X;
}

int main()
{
    int N, M, x;
    scanf ("%d %d", &N, &M);
    Creat();
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        Insert(x);
    }
    int j;
    for (int i = 0; i < M; i++)
    {
        while(j > 1)
        {
            j /= 2;
            printf("%d", H[j]);//控制格式
        }
        printf("\n");
    }
    return 0;
}