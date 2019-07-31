//转录于https://www.cnblogs.com/yi2105/p/10840943.html
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define max 10
typedef int vertex_type;
typedef int edge_type;
typedef struct graph_matrix{
    int n, e;//顶点数n，边数e
    vertex_type vexs[max];//顶点一维数组
    edge_type edges[max][max];//邻接矩阵二维数组,元素类型为vector<vertex_type>
}gm;

//函数声明
void create_gm(gm &gm);
void DFS(gm &gm, int id);
void BFS(gm &gm, int id);

//visit[]数组；全局变量
int visit[max] = {0};

int main()
{
    gm gm;//定义一个叫做gm的邻接矩阵
    create_gm(gm);

    //调用DFS遍历
    for(int i = 0; i < gm.n; i++)
    {
        if(visit[i] == 1)continue;
        cout << "{";
        DFS(gm, i);
        cout <<"}" <<endl;
    }

    //重置visit[]数组
    memset (visit, 0, sizeof(visit));

    //调用BFS遍历
    for(int i = 0; i < gm.n; i++)
    {
        if(visit[i] == 0){
            cout << "{ ";
            BFS(gm, i);
            cout << "}" << endl;
        }
    }
    return 0;
}

//创建图
void create_gm(gm &gm)
{
    cin>>gm.n>>gm.e;
    memset(gm.edges, 0, sizeof(gm.edges));
    for(int i = 0; i<gm.n; i++){
        gm.vexs[i] = i;
    }

    //输入边数据
    int a, b;
    for(int i = 0; i<gm.e; i++)
    {
        cin>>a>>b;
        gm.edges[a][b] = 1;
        gm.edges[b][a] = 1;
    }
}

//深度优先
void DFS(gm &gm, int id)
{
    visit[id] = 1;
    cout << id << " ";
    for(int i = 0; i<gm.n; i++)
    {
        if(gm.edges[i][id] == 1 && visit[i] == 0){
            DFS(gm, i);
        }
    }
}

//宽度优先
void BFS(gm &gm, int id)
{
    visit[id] = 1;
    queue<int> qu;
    qu.push(id);
    while(qu.size() != 0){
        int mark = qu.front();
        qu.pop();
        cout<<mark<<" ";
        for(int i = 0; i<gm.n; i++)
        {
            if(gm.edges[i][mark] == 1 && visit[i] == 0)
            {
                visit[i] = 1;
                qu.push(i);
            }
        }
    }
}