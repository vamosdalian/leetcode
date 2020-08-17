#include "include.h"

// #include <bits/stdc++.h>

using namespace std;
int res = -1;

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
//多个数字
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

void backtrack(vector<int> prices, vector<int> &path, int count,int &tmpcount){
    if(tmpcount == count && path.size() < res){
        res = path.size();
        return;
    }
    if(tmpcount > count) return;
    for(int i = prices.size() - 1; i >= 0; i--){
        path.push_back(prices[i]);
        tmpcount += prices[i];
        // cout << prices[i]<<endl;
        backtrack(prices, path, count, tmpcount);
        tmpcount -= prices[i];
        path.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    vector<int> prices = getNums<int>(' ');
    int cont = getNum<int>();
    if(prices.size() == 0){
        cout << -1 << endl;
        return 0;
    }else if(cont == 0){
        cout << -1 << endl;
        return 0;
    }
    sort(prices.begin(), prices.end());
    // cout << prices[0];
    vector<int> path;
    int tmpcont = 0;
    backtrack(prices, path,cont,tmpcont);
    cout << res <<endl;
    return 0;
}
