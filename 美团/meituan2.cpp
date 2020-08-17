#include "include.h"
#include <bits/stdc++.h>
using namespace std;

//获取一个数字
template <typename T>
T getNum(){
    T result = 0;
    string str;
    bool isFushu = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '-'){
            isFushu = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}
//获取多个字符串
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
//获取二维字符串
vector< vector <string> > getStrings2(char c = ' '){
    vector< vector <string> > result;
    vector< string > tmpString;
    while (true)
    {
        tmpString = getStrings(' ');
        if(tmpString.size() == 0) break;
        result.push_back(tmpString);
        tmpString.clear();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    vector<vector<string> > travel;
    for(int i = 0;i < n ; i++){
        travel.push_back(getStrings(' '));
    }
    string start;
    int count = 0;
    for(int i = 0;i < n;i++){
        if(start.size() == 0){
            start = travel[i][0];
            continue;
        }
        if(travel[i][1] == start){
            count++;
            start.clear();
        }
    }
    cout << count << endl;
    return 0;
}
