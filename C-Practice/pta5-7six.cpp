//转录于https://www.cnblogs.com/claremore/p/4869523.html

#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10005;

int vertices, edges;
vector<int> G[maxn]; //每个vector结构的元素表示：与数组下标代表的节点右边的节点
bool vis[maxn]; //是否访问过

int BFS(int v)
{
    for(int i = 0; i < maxn; i++)
        vis[i] = false;
    int tail; //用于记录每层压入时的节点
    int last = v;//记录每层的最后一个元素：该层压入之后弹出之前更新： last=temp;
    int count = 1;
    int level = 0;

    vis[v] = true;
    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int x = q.front(); //弹出x
        q.pop();
        for(int j = 0; j < G[x].size(); j++)//x的一圈压入队列
        {
            if(!vis[G[x][j]])//若未被访问过：访问并压入队列
            {
                vis[G[x][j]] = true;
                q.push(G[x][j]);
                tail = G[x][j]; //记录压入的节点
                count++;
            }
        }
        if(x==last)//一层全部弹出，准备开始弹下一层：弹出的(x)=当前层最后一个元素(last)
        {
            last=tail; //一层全部压入完后，更新last
            level++;
        }
        if(level==6)
            break;
    }
    return count;
}

int main(int argc, char** argv){
    int x,y;
    cin>>vertices>>edges;

    for(int i = 1; i<=edges; i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int j = 1; j <= vertices; j++)
    {
        printf("%d: %.2lf%%\n", j, BFS(j)*1.0/vertices*100.0);//格式输出
    }
    return 0;
}