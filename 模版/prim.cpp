//Prim（普瑞姆）代码模版
//用途    ： 最小生成树
//输入    ： 无向图，邻接表(必须是连通图)
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

int Prim(vector<vector<int> > G, vector<int> V){
    int result = 0;
    unordered_set<int> visited;
    visited.insert(V[0]);
    while(visited.size() < V.size()){
        int min = INT_MAX;
        vector<int> index(2,-1);
        for(auto g : G){
            if(visited.find(g[0]) != visited.end() || visited.find(g[1]) != visited.end()){
                if(g[2] < min){
                    min = g[2];
                    index[0] = g[0];
                    index[1] = g[1];
                }
            }
        }
        result += min;
        visited.insert(index[0]);
        visited.insert(index[1]);
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
    cout << Prim(graph, v);
    return 0;
}
