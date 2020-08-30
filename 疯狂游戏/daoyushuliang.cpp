#include "include.h"

// #include "bits/stdc++.h"

using namespace std;

//获取一维字符串组
vector<string> getStrings(char c = ' '){
    vector<string> result;
    string str;
    string tmpStr;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            if(!tmpStr.empty()){
                result.push_back(tmpStr);
                tmpStr.clear();
            }
            continue;
        }
        tmpStr.push_back(str[i]);
    }
    result.push_back(tmpStr);
    return result;
}

void bfs(vector<string> &maps,vector<vector<int> > &visited, int i, int j){
    deque<vector<int> > myque;
    myque.push_back({i,j});
    visited[i][j] = 1;
    while(!myque.empty()){
        auto item = myque.front();
        maps[item[0]][item[1]] = '0';
        if(item[0] - 1 >= 0 && maps[item[0] - 1][item[1]] == '1' && visited[item[0] - 1][item[1]] == 0){
            myque.push_back({item[0] - 1,item[1] });
            visited[item[0] - 1][item[1]] = 1;
        }
        if(item[0] + 1 < maps.size() && maps[item[0] + 1][item[1]] == '1' && visited[item[0] + 1][item[1]] == 0){
            myque.push_back({item[0] + 1, item[1]});
            visited[item[0] + 1][item[1]] = 1;
        }
        if(item[1] - 1 >= 0 && maps[item[0]][item[1] - 1] == '1' && visited[item[0]][item[1] - 1] == 0){
            myque.push_back({item[0], item[1] - 1});
            visited[item[0]][item[1] - 1] = 1;
        }
        if(item[1] + 1 < maps[0].size() && maps[item[0]][item[1] + 1] == '1' && visited[item[0]][item[1] + 1] == 0){
            myque.push_back({item[0], item[1] + 1});
            visited[item[0]][item[1] + 1] = 1;
        }
        myque.pop_front();
    }
}

int getIslands(vector<string> &maps){
    int count = 0;
    vector<vector<int> > visited(maps.size(), vector<int>(maps[0].size(),0));
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if(maps[i][j] == '1'){
                // cout << i << ":" << j << endl;
                bfs(maps, visited, i, j);
                count++;
            }
            
        }
        
    }
    return count;
    
}

int main(int argc, char const *argv[])
{
    vector<string> maps = getStrings(',');
    if(maps.size() == 0){
        cout << 0<<endl;
    }
    else{
        cout << getIslands(maps);
    }
    return 0;
}


// 11000
// 11000
// 00100
// 00011
// 3