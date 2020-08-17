#include "include.h"

using namespace std;

//定义常用变量 
#define ll long long

/***
以下函数可以直接用（algorithm头文件）
求和函数         accumulate(vec.begin() , vec.end() , 0);//0初始变量
查找            find(vec.begin(), vec.end(), 30);//寻找myvector中等于30的元素
排序            sort(vec.begin() , vec.end());
逆转            reverse(vec.begin() , vec.end());

字符串相关
字符串转数字     to_string(int i);
数字转字符串     atoi(str.c_str());
***/


//常用输入
//------------------------------
//从屏幕输入n个数字
vector<int> getNums(char c = ' '){
    //获取输入的数组，返回
    vector<int> result;
    string str;
    int tmp = 0;
    bool minus = false;
    getline(cin, str);
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
//从屏幕输入n个字符串
vector<string> getStrings(char c = ' '){
    vector<string> result;
    string str;
    string tmpStr;
    getline(cin, str);
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
//从键盘输入1个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}
//从键盘输入1个数字
int getNum(){
    string str;
    int result = 0;
    bool minus = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '-'){
            minus = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = minus? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}



int main(int argc, char const *argv[]){

    return 0;
}
