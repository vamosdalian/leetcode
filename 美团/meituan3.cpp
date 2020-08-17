#include "include.h"
#include <unordered_set>

using namespace std;

//获取多个数字
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

int main(int argc, char const *argv[])
{
    //无向图子图
    vector<int> tmpvac = getNums<int>(' ');
    int n = tmpvac[0];
    int m = tmpvac[1];
    vector<vector<int> > graph;
    for(int i = 0; i < m ; i++){
        tmpvac = getNums<int>(' ');
        graph.push_back(tmpvac);
    }
    vector<unordered_set<int> > result;
    for(int i = 0; i < m ; i++){
        int j = 0;
        for(j = 0; j < result.size();j++){
            if(result[j].find(graph[i][0]) == result[j].end()){
                result[j].insert(graph[i][1]);
                break;
            }else if(result[j].find(graph[i][1]) == result[j].end()){
                result[j].insert(graph[i][0]);
                break;
            }
        }
        if(j == result.size()){
            unordered_set<int> tmpset;
            tmpset.insert(graph[i][0]);
            tmpset.insert(graph[i][1]);
            result.push_back(tmpset);
        }
    }
    return 0;
}


