#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
 
using namespace std;
 
struct node
{
    int end;//终点
    int power;//权值
} t;
 
int n;//n为边数
vector<node>q[500001];//邻接表存储图的信息（相当于一个存储着结构体的二维数组）
int dis[500001];//距离数组
bool vis[500001];//标记数组
 
void Dijkstra(int start, int end)
{
    memset(vis, false, sizeof(vis));
    for(int i=0; i<=n; i++)
    {
        dis[i] = INF;
    }
    int len=q[start].size();
    for(int i=0; i<len; i++)
    {
        if(q[start][i].power < dis[q[start][i].end] )
            dis[q[start][i].end]=q[start][i].power; //从起点开始的dis数组更新
    }
 
    vis[start]=true;//起点标记为1
 
    for(int k=0; k<n-1; k++)
    {
        int pos, min=INF;
        for(int i=1; i<=n; i++)
        {
            if( !vis[i] && dis[i]<min )
            {
                //当前节点未被访问过且权值较小
                min=dis[i];
                pos=i;
            }
        }
 
        vis[pos]=true;
 
        //再次更新dis数组
        len=q[pos].size();
        for(int j=0; j<len; j++)
        {
            if( !vis[q[pos][j].end] && dis[ q[pos][j].end ]>q[pos][j].power+dis[pos] )
                dis[q[pos][j].end ] = q[pos][j].power + dis[pos];
        }
    }
    printf("%d\n", dis[end] );
}
 
 
int main()
{
    int m;
    if(scanf("%d %d", &n, &m)&&n&&m)//输入点和边
    {
        for(int i=0; i<=n; i++)
            q[i].clear();//将vector数组清空
        for(int i=0; i<m; i++)
        {
            int begin,end, power;
            scanf("%d %d %d", &begin, &end, &power);//输入
            /*t作为node型临时变量，为了方便压入,以下代码为无向图的输入边*/
            t.end=end;
            t.power=power;
            q[begin].push_back(t);  //输入的数据依次存到q[begin][0]、q[begin][1]里
            t.end=begin;
            t.power=power;
            q[end].push_back(t);
        }
        //Dijkstra(1, n);
        int start, end;//自己确定起始点和终止点
        start = 0;
        scanf("%d", &end);//输入起始点和终止点
        Dijkstra(start, end);
    }
    return 0;
}