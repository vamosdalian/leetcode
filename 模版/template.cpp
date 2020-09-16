
#include "include.h"

//#include <bits/stdc++.h>

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
//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}
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
//获取二维字符串
vector< vector <string> > getStrings2(int n, char c = ' '){
    vector< vector <string> > result;
    vector< string > tmpString;
    while (n--)
    {
        tmpString = getStrings(' ');
        if(tmpString.size() == 0) break;
        result.push_back(tmpString);
        tmpString.clear();
    }
    return result;
}

//输出一维vector
template <typename T>
void printVector(vector<T> input, string str = "\t"){
    for(int i = 0; i < input.size(); ++i){
        cout << input[i] << str;
    }
    cout << endl;
}

//输出二维vector
template <typename T>
void printVector2(vector<vector<T> > input, string str = "\t"){
    for(int i = 0 ; i < input.size(); ++i){
        for(int j = 0; j < input[i].size(); ++j){
            cout << input[i][j] << str;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // vector<vector<string> > nums = getStrings2(2);
    // printVector2(nums);
    int num = getNum<int>();
    cout << num;
    return 0;
}

