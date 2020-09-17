//Dijkstra（迪杰斯特拉）代码模版
//用途    ： 获取图单点到各点的最短路径
//输入    ： 无向图，邻接表
//author ： 孟凡宇
//email  ： elve960520@163.com

#include "include.h"

using namespace std;

//获取一维数组
template <typename T>
vector<T> getNums(char c = ' '){
    vector<T> result;
    string str;
    T tmp = 0;
    bool minus = false;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            result.push_back(tmp);
            tmp = 0;
            minus = false;
            continue;
        }
        if(str[i] == '-'){
            minus = true;
            continue;
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

//获取二维数组
template <typename T>
vector< vector<T> > getNums2(int n, char c = ' '){
    vector< vector<T> > result;
    vector<T > tmpResult;
    while(n--){
        tmpResult = getNums<T>(c);
        if(tmpResult.size() == 0) break;
        result.push_back(tmpResult);
        tmpResult.clear();
    }
    return result;
}
//狄杰斯特拉 (无向图)
unordered_map<int, int> Dijkstra(vector<vector<int> > G, vector<int> V, int start){ 
    unordered_map<int, int> dists;
    unordered_map<int, int> result;
    //初始化最短路径
    for(auto v : V){
        dists.insert(make_pair(v, INT_MAX));
    }
    for(auto g : G){
        if(g[0] == start && g[2] < dists[g[1]]){
            dists[g[1]] = g[2];
        }else if(g[1] == start && g[2] < dists[g[0]]){
            dists[g[0]] = g[2];
        }
    }
    dists[start] = 0;
    result.insert(make_pair(start, 0));
    int tmp = start;

    for(int i = 1; i < V.size(); i++){
        int index = -1;
        int min = INT_MAX;
        for(auto g : G){
            if(g[0] == tmp && result.find(g[1]) == result.end() && g[2] + dists[g[0]] <= dists[g[1]]){
                dists[g[1]] = g[2] + dists[g[0]];
            }else if(g[1] == tmp && result.find(g[0]) == result.end() && g[2] + dists[g[1]] <= dists[g[0]]){
                dists[g[0]] = g[2] + dists[g[1]];
            }
        }
        for(auto dist : dists){
            if(dist.second <= min && result.find(dist.first) == result.end()){
                index = dist.first;
                min = dist.second;
            }
        }
        tmp = index;
        result.insert(make_pair(index, min));
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nAm = getNums<int>();
    vector<vector<int> > graph = getNums2<int>(nAm[1]);
    vector<int> v;
    for (int i = 0; i < nAm[0]; i++)
    {
        v.push_back(i);
    }
    auto result = Dijkstra(graph, v, 0);
    for(auto re : result){
        cout << re.first << "-->" << re.second<<endl;
    }
    return 0;
}
/*
inputs:
5 5
0 1 100
1 2 150
2 0 400
0 4 300
1 4 100

*/